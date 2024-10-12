#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9 + 7;

struct matrix{
    ll a[2][2];
    friend matrix operator * (matrix x, matrix y){
        matrix kq;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                kq.a[i][j] = 0;
                for(int k = 0; k < 2; k++){
                    kq.a[i][j] += x.a[i][k] * y.a[k][j];
                    kq.a[i][j] %= mod;
                }
            }
        }
        return kq;
    }
};

matrix powMod(matrix a, ll n){
    if(n == 1) return a;
    matrix kq = powMod(a, n / 2);
    if(n % 2) return kq * kq * a;
    else return kq * kq;
}

int main(){
    matrix x;
    x.a[0][0] = 1; x.a[0][1] = 1;
    x.a[1][0] = 1; x.a[1][1] = 0;
    ll n; cin >> n;
    matrix y = powMod(x, n);
    cout << y.a[0][1];
}
