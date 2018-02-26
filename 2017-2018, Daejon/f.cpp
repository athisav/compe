#include <bits/stdc++.h>
using namespace std;

int x, y;

void solve(int dir, int dex, int t, int l, bool f) {
    if (t == 0) {
        if (f) {
            x += l - 1;
            y += l - 1;
        }
        return;
    }
    
    int hl = l / 2;
    int k = t / (hl * hl);
    int nextdir = dir;
    int nextdex = dex;
    
    if (k == 0)
        nextdir = (dir + 1) % 2;
    if (k == 3) {
        nextdir = (dir + 1) % 2;
        nextdex = (dex + 2) % 4;
        f = !f;
    }
    
    int temp = ((dir == 1) ? (4 + dex - k) : (dex + k)) % 4;
    if (temp == 1)
        y = y + hl;
    if (temp == 2) {
        x = x + hl;
        y = y + hl;
    }
    if (temp == 3)
        x = x + hl;
    
    solve(nextdir, nextdex, t - (hl * hl * k), hl, f);
}

int main() {
    int n, m;
    cin >> n >> m;
    x = y = 1;
    solve(0, 0, m - 1, n, false);
    cout << x << " " << y << endl;
}
