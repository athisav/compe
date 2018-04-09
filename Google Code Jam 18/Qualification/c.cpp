#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin >> t;
    for(int z = 1; z <= t; z++){
        ll g;
        cin >> g;
        bool d = 0;
        for(ll r = 0; r < 5; r++){
            for(ll c = 0; c < 5; c++){
                if(d == 1){break;}
                ll l = 9;
                vector<vector<int>> b(3, vector<int>(3, false));
                ll rr = 2 + 3*r;
                ll cc = 2 + 3*c;
                while(l > 0){
                    cout << rr << " " << cc << endl;
                    ll rd, cd;
                    cin >> rd >> cd;
                    if(rd == 0 && cd == 0){
                        d = 1;
                        break;
                    } else if(rd == -1 && cd == -1){
                        return 0;
                    } else{
                        ll r2 = (rd - rr) + 1;
                        ll c2 = (cd - cc) + 1;
                        if(b[r2][c2]){
                        } else{
                            l--;
                            b[r2][c2] = true;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
//UNTESTED
