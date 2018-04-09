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

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    auto good = [&](long long mask) {
        for (int i = 0; i < n; i++) {
            vector<int> can(51, false);
            can[a[i]] = true;
            for (int j = 50; j >= 0; j--) {
                if (can[j]) {
                    for (int u = 1; u <= 50; u++) {
                        if (mask & (1LL << u)) {
                            can[j % u] = true;
                        }
                    }
                }
            }
            if (!can[b[i]]) {
                return false;
            }
        }
        return true;
    };
    long long mask = (1LL << 51) - 1;
    if (!good(mask)) {
        cout << -1 << '\n';
        return 0;
    }
    for (int bit = 50; bit >= 0; bit--) {
        if (good(mask ^ (1LL << bit))) {
            mask ^= (1LL << bit);
        }
    }
    cout << mask << '\n';
    return 0;
}
