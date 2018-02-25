#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a;
int main()
{
    cin >> a;
    ll t = 1, n = a, s = 0;
    while(n / 10){
        n /= 10;
        t *= 10;
        s += 9;
    }
    if((n + 1)*t - 1 <= a){
        s += n;
    }
    else s += (n - 1);
    cout << s << endl;
    return 0;
}
