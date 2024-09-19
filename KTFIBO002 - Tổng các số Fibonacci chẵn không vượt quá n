#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll f[100];

void fibo(){
    f[1] = f[2] = 1;
    for(int i = 3; i <= 92; i++){
        f[i] = f[i-1] + f[i-2];
    }
}

int main(){
    fibo();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll sum = 0;
        for(int i = 3; i <= 92; i++){
            if(f[i] <= n && f[i] % 2 == 0) sum += f[i];
        }
        cout << sum << endl;
    }
    return 0;
}
