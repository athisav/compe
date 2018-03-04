#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(),c.end()

const int MAXN = 200010;

int p[MAXN], v[MAXN], x[MAXN];
multiset<int> s[MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> p[i];
        x[i] = i;
    }
    
    for (int i = n; i >= 1; i--)
    {
        auto it = s[x[i]].upper_bound(v[i]-1);
        if (it != s[x[i]].end())
        {
            s[x[i]].erase(it);
        }
        s[x[i]].insert(v[i]);
        if(s[x[i]].size() < s[x[p[i]]].size())
        {
            s[x[p[i]]].insert(all(s[x[i]]));
        }
        else
        {
            s[x[i]].insert(all(s[x[p[i]]]));
            x[p[i]] = x[i];
        }
    }
    
    cout << (int)s[x[0]].size() << endl;
}
