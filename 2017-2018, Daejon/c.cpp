#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> e[N];
int go[N];

int dfs(int ver, int len){
    if(go[ver] != 0){
        return go[ver] + len - 1;
    }
    int get = len;
    for(auto it : e[ver])
    {
        if(e[ver].size() < e[it].size())
        {
            get = max(get, dfs(it, len + 1));
        }
    }
    return get;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m ; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        go[i] = dfs(i, 1);
        ans = max(ans, go[i]);
    }
    cout << ans << endl;
    return 0;
}
