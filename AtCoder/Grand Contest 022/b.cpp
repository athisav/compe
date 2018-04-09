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

int n, w[20100], cnt = 0;
int main(){
    cin >> n;
    if (n == 3){
        cout << 2 << " " << 5 << " " << 63 << endl;;
        return 0;
    }
    if (n == 4){
        cout << 2 << " " << 5 << " " << 20 << " " << 63 << endl;
        return 0;
    }
    int pv1 = 2, pv2 = 3, pv3 = 6, ck = 1;
    if(n%2==1)w[++cnt] = 6, pv3 += 6;
    while (cnt < n && ck){
        ck = 0;
        if (pv1 + 2 <= 30000 && cnt+2 <= n){
            w[++cnt] = pv1;
            w[++cnt] = pv1 + 2;
            pv1 += 6;
            ck = 1;
        }
        if (pv2 + 6 <= 30000 && cnt+2 <= n){
            w[++cnt] = pv2;
            w[++cnt] = pv2 + 6;
            pv2 += 12;
            ck = 1;
        }
    }
    while (cnt < n){
        w[++cnt] = pv3;
        pv3 += 6;
    }
    for (int i = 1; i <= cnt; i++){
        cout << w[i] << " ";
    }
    cout << endl;
}
