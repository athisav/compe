#include <bits/stdc++.h>
using namespace std;

map<int, bool> check;

int proc(int b)
{
    int tmpb = b, ans = 0;
    while(tmpb)
    {
        int mod = tmpb % 10;
        tmpb /= 10;
        ans += mod * mod;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int a = n;
    while(a != 1 && !check.count(a))
    {
        check[a] = 1;
        a = proc(a);
    }
    cout << (a == 1 ? "HAPPY" : "UNHAPPY") << endl;
    return 0;
}
