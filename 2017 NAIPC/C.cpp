#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int>pi;

const int MAXN = 313, mod = 1e9+7;
int g0[MAXN][MAXN][2];
int g1[MAXN][MAXN][2];
int a[MAXN];
int ok[MAXN][MAXN];

inline void up(int &x,int y)
{
    x+=y;if(x>=mod)x-=mod;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ok[i][j] = __gcd(a[i],a[j]) > 1;
        }
    }
    for(int i = 0; i < n ; i++)
    {
        g0[i][i][0] = g1[i][i][0] = 1;
    }
    for(int len = 2; len <= n; len++)
    {
        for(int l = 0; l < n; l++)
        {
            int r = l + len-1;
            if(r >= n)break;
            g0[l][r][0] = g0[l][r][1] = 0;
            for(int br = l;br < r; br++)
            {
                up(g0[l][r][0], 1LL * g0[l][br][1] * g0[br][r][0] % mod);
                if(ok[l][r])up(g0[l][r][1], 1LL * g0[l][br][0] * g1[br + 1][r][0] % mod);
            }
            up(g0[l][r][0], g0[l][r][1]);
            g1[l][r][0] = g1[l][r][1] = 0;
            for(int bl = r; bl > l; bl--)
            {
                up(g1[l][r][0], 1LL * g1[bl][r][1] * g1[l][bl][0] % mod);
                if(ok[l][r])up(g1[l][r][1], 1LL * g1[bl][r][0] * g0[l][bl-1][0] % mod);
            }
            up(g1[l][r][0], g1[l][r][1]);
        }
    }
    cout << g0[0][n-1][0] << endl;
    return 0;
}
