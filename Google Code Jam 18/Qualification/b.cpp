#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> a, b;

ll r(ll i){
    return i%2 == 0 ? a[i/2] : b[i/2];
}

int main()
{
    int t;
    cin >> t;
    for(int z = 1; z <= t; z++){
        ll n;
        cin >> n;
        
        a.clear();
        b.clear();
        
        for(ll i = 0; i < n; i++){
            ll x;
            cin >> x;
            if(i%2 == 0){
                a.push_back(x);
            }
            else{
                b.push_back(x);
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        bool k = true;
        for(ll i = 0; i < n-1; i++){
            ll aa = r(i);
            ll ab = r(i + 1);
            if(k && aa > ab){
                cout << "Case #" << z << ": " << i << endl;
                k = false;
            }
        }
        if(k){
            cout << "Case #" << z << ": " << "OK" << endl;
        }
    }
    return 0;
}

