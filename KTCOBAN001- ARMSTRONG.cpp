#include <bits/stdc++.h>
using namespace std;

int cnt(long long n){
    int cnt = 0;
    while(n > 0){
        cnt++;
        n /= 10;
    }
    return cnt;
}

bool check(long long n){
    long long m = n, sum = 0;
    int x = cnt(n);
    while(n > 0){
        sum += round(pow(n % 10, x));
        n /= 10;
    }
    return sum == m;
}

int main(){
    int t; cin >> t;
    while(t--){
        long long n; cin >> n;
        if(check(n)) cout << 1;
        else cout << 0;
        cout << endl;
    }
}
