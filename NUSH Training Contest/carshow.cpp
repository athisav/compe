#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    assert(1 <= n && n <= 100000);
    assert(1 <= q && q <= 100000);
    int a[n + 1];
    map<int, int> lpos;
    int d[n + 1] = {0};
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        assert(1 <= a[i] && a[i] <= 1000000);
        d[i] = max(d[i - 1], lpos[a[i]]);
        lpos[a[i]] = i;
    }
    int64_t ds[n + 1];
    partial_sum(d, d + n + 1, ds);
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        int m = lower_bound(d + l, d + r + 1, l) - d;
        cout << 1LL * (l + r) * (r - l + 1) / 2 - (ds[r] - ds[m - 1]) - 1LL * (m - l) * (l - 1) << endl;
    }
    return 0;
}
