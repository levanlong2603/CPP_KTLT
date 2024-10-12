#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9 + 7;

ll n, k;
struct matrix{
    ll a[20][20];
    friend matrix operator * (matrix x, matrix y){
        matrix kq;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                kq.a[i][j] = 0;
                for(int k = 0; k < n; k++){
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
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        matrix x;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> x.a[i][j];
            }
        }
        matrix y = powMod(x, k);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << y.a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
