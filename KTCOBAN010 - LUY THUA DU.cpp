#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long binPow(long long n, long long a){
    if(a == 0) return 1;
    long long x = binPow(n, a / 2);
    if(a % 2 == 1) return ((x % mod) * (x % mod) % mod) *(n % mod) % mod;
    else return (x % mod) * (x % mod) % mod;
}

int main(){
    int t; cin >> t;
    while(t--){
        long long a, n; cin >> a >> n;
        cout << binPow(a, n) << endl;
    }

    return 0;
}
