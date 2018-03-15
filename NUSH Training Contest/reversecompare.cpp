#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cnt[1000];

int main()
{
    string s;
    cin >> s;
    ll ans = 1;
    for (int i = 0; i < s.length(); i++) {
        ans += i - cnt[s[i]];
        cnt[s[i]]++;
    }
    cout << ans << endl;
    
    return 0;
}
