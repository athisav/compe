#include <bits/stdc++.h>
using namespace std;

//Divide & Conquer

const int max = 262144;

int a[max];
int next[max], prev[max];
map<int, int> bb;

int dfs(int l, int r) {
    if(l >= r)    return 1;
    for(int i = 0; i <= (r-l+1)/2; i++) {
        if(next[l+i] > r && prev[l+i] < l)
        return dfs(l, l+i-1) && dfs(l+i+1, r);
        if(next[r-i] > r && prev[r-i] < l)
        return dfs(l, r-i-1) && dfs(r-i+1, r);
    }
    return 0;
}

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            next[i] = n+1;
            prev[i] = 0;
        }
        bb.clear();
        for(int i = 1; i <= n; i++) {
            prev[i] = bb[a[i]], next[prev[i]] = i;
            bb[a[i]] = i;
        }
        cout << (dfs(1, n) ? "non-boring" : "boring") << endl;;
    }
    return 0;
}
