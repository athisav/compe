#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cek(const string &s){
    ll ans = 0;
    ll charge = 1;
    for(auto& c : s){
        if(c == 'S'){
            ans += charge;
        }else{
            charge *= 2;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    for(int z = 1; z <= t; z++){
        ll d;
        string s;
        cin >> d >> s;
        ll ans = 0;
        while(cek(s) > d){
            bool change = 0;
            for(ll i = s.size() - 2; i >= 0; i--){
                if(s[i] == 'C' && s[i + 1] == 'S'){
                    s[i] = 'S';
                    s[i + 1] = 'C';
                    ans++;
                    change = 1;
                    break;
                }
            }
            if(!change){
                break;
            }
        }
        if(cek(s) > d){
            cout << "Case #" << z << ": IMPOSSIBLE" << endl;
        }
        else{
            cout << "Case #" << z << ": " << ans << endl;
        }
    }
    return 0;
}
