#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll a[100005];
void solve(ll x, ll n){
    a[0] = 1;
    ll q, r = 0, m = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            q = a[j] * x + r;
            a[j] = q % 10;
            r = q / 10;
        }
        while(r > 0){
            a[m] = r % 10;
            r /= 10;
            m++;
        }
    }
    for(int i = m - 1; i >= 0; i--){
        cout << a[i];
    }
    cout << endl;
}


int main(){
    int t; cin >> t;
    while(t--){
        ll a, n;
        cin >> a >> n;
        solve(a, n);
    }
    return 0;
}
