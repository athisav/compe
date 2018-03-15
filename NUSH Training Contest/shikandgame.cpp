#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

struct seg{
    lint tree[270000];
    int lim;
    void init(int n){
        memset(tree, 0x3f, sizeof(tree));
        for(lim = 1; lim <= n; lim <<= 1);
    }
    void update(int x, lint v){
        x += lim;
        tree[x] = min(tree[x], v);
        while(x > 1){
            x >>= 1;
            tree[x] = min(tree[2*x], tree[2*x+1]);
        }
    }
    lint query(int s, int e){
        s += lim;
        e += lim;
        lint ret = 1e18;
        while(s < e){
            if(s%2 == 1) ret = min(ret, tree[s++]);
            if(e%2 == 0) ret = min(ret, tree[e--]);
            s >>= 1;
            e >>= 1;
        }
        if(s == e) ret = min(ret, tree[s]);
        return ret;
    }
}seg;

int n, e, t, a[100005];
lint dp[100005];


int main(){
    cin >> n >> e >> t;
    lint curmin = 1e18;
    int p = 0;
    seg.init(n);
    seg.update(0, 0);
    for(int i=1; i<=n; i++){
        cin >> a[i];
        while(p < i && 2 * a[i] - 2 * a[p+1] >= t){
            curmin = min(curmin, dp[p] - 2 * a[p+1]);
            p++;
        }
        dp[i] = curmin + 2 * a[i];
        dp[i] = min(dp[i], seg.query(p, i-1) + t);
        seg.update(i, dp[i]);
    }
    cout << dp[n] + e << endl;
}
