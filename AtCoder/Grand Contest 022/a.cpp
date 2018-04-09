/*
 Jugemu Jugemu
 Goko-no surikire
 Kaijarisuigyo-no
 Suigyomatsu Unraimatsu Furaimatsu
 Kuunerutokoro-ni Sumutokoro
 Yaburakoji-no burakoji
 Paipopaipo Paipo-no-shuringan
 Shuringan-no Gurindai
 Gurindai-no Ponpokopi-no Ponpokona-no
 Chokyumei-no Chosuke
 */

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;

string s;
bool cek[26];

int main(){
    cin >> s;
    for (auto &c : s){
        cek[c - 'a'] = 1;
    }
    if (s.length() < 26) {
        char g = 'a';
        while (cek[g - 'a']) {
            ++g;
        }
        s.pb(g);
        cout << s << endl;
        return 0;
    }
    for (int i = 25; i >= 0; --i){
        for (int j = s[i] - 'a' + 1; j < 26; ++j){
            if (!cek[j]){
                s[i] = 'a' + j;
                cout << s << endl;
                return 0;
            }
        }
        cek[s[i] - 'a'] = false;
        s.pop_back();
    }
    cout << -1 << endl;
    return 0;
}
