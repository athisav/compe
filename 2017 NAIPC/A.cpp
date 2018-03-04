#include <bits/stdc++.h>
using namespace std;

const int N = 310,inf = 1000000;
int f[N * N], g[N * N];

struct P {
    int x, y, w;
    int type, p;
    void cal() {
        if(y >= 0){
            type = 1;
            p = -x;
        }
        else{
            type = 0;
            p = y-x;
        }
    }
}a[N];

inline bool cmp(const P &a,const P &b){
    if(a.type != b.type)
    {
        return a.type > b.type;
    }
    if(a.type == 1)
    {
        return a.p < b.p;
    }
    return a.p > b.p;
}

int main()
{
    int n;
    cin >> n;
    string s;
    int all = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        for(int j = 0; j < s.length(); j++)
        {
            if(s[j]=='('){
                a[i].y++;
            }
            else{
                a[i].y--;
            }
            a[i].x=min(a[i].x,a[i].y);
        }
        a[i].w = s.length();
        a[i].cal();
        all += s.length();
    }
    sort(a+1,a+n+1,cmp);
    for(int i = 1; i <= all; i++)f[i]=-inf; //INIT
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= all; j++)g[j]=f[j];
        for(int j = 0; j <= all; j++)if(j+a[i].x>=0&&f[j]>=0)g[j+a[i].y]=max(g[j+a[i].y],f[j]+a[i].w);
        for(int j = 0; j<=all; j++)f[j]=g[j];
    }
    cout << f[0] << endl;;
}
