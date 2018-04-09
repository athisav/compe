#include<cstdio>
#include <bits/stdc++.h>
using namespace std;
string p;
int n, v[30];

int main()
{
    int ck = 0;
    cin >> p;
    for (int i = 0; p[i]; i++)
    {
        v[p[i] - 'a'] = 1;
        if (p[i] + i != 'z')
        {
            ck = 1;
        }
    }
    n = p.length();
    if (n != 26)
    {
        int i;
        for (i = 0; i < 26; i++)if (!v[i])break;
        p[n] = i + 'a';
        cout << p << endl;
        return 0;
    }
    if (ck == 0) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++)v[j] = 0;
        for (int j = 0; j < i; j++) {
            v[p[j] - 'a'] = 1;
        }
        for (int j = p[i] - 'a' + 1; j < 26; j++) {
            if (!v[j]) {
                v[j] = 1;
                p[i] = 'a' + j;
                p[i + 1] = 0;
                cout << p << endl;
                return 0;
            }
        }
    }
}
