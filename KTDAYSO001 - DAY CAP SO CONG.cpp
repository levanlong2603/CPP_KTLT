#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool check(ll a[], int n){
    ll d = a[1] - a[0];
    for(int i = 1; i < n; i++){
        if(a[i] - a[i - 1] != d){
            return false;
        }
    }
    return true;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll a[n];
        for(ll &x : a) cin >> x;
        if(check(a, n)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
