#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int dp[310][310][310];

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    for(int i = s.size()-1; i >= 0; i--){
        for(int a = 0; a <= k; a++){
            if(i > 0) dp[i][i-1][a] = 0;
        }
    }
    for(int i = s.size()-1; i >= 0; i--)
    {
        for(int j = i; j < s.size(); j++)
        {
            for(int a = 0; a <= k; a++)
            {
                dp[i][j][a] = 1;
                if(i == j) continue;
                dp[i][j][a] = max(dp[i][j][a], dp[i+1][j][a]);
                dp[i][j][a] = max(dp[i][j][a], dp[i][j-1][a]);
                if(s[i] == s[j])
                {
                    dp[i][j][a] = max(dp[i][j][a], 2 + dp[i+1][j-1][a]);
                } else
                {
                    if(a > 0)
                    {
                        dp[i][j][a] = max(dp[i][j][a], dp[i+1][j-1][a-1] + 2);
                    }
                }
            }
        }
    }
    
    
    cout << dp[0][s.size()-1][k] << endl;
}
