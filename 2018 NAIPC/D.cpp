#include <bits/stdc++.h>
using namespace std;

bool cek[100001] = {false};
int a[100000];

int main(){
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        cin >> a[i];
        cek[a[i]] = true;
    }
    
    int b = 1;
    for(int i = 0; i < m; i++){
        while(b <= n){
            if(cek[b]){
                b++;
            }
            else if(b < a[i]){
                cout << b++ << endl;
            }
            else{
                break;
            }
        }
        cout << a[i] << endl;
    }
    
    for(; b <= n; b++){
        if(!cek[b]){
            cout << b << endl;
        }
    }
    
    return 0;
}
