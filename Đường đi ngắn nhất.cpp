#include <iostream>
#include <math.h>

using namespace std;
#define ll long long
#define MOD 1000000007

ll  t, m, n, dp[200][200], a[200][200], x, y;

void solve(){
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    
    cin >> x >> y;

    for(int i = 1; i < n; i++){
        dp[0][i] = 1e9;
        dp[m + 1][i] = 1e9;
    }
    for(int i = 1; i <= m; i++){
        if(i != x){
            a[i][y] = 1e9;
        }
        dp[i][y] = a[i][y];
    }
    for(int j = y + 1; j <= n; j++){
        for(int i = 1; i <= m; i++){
            dp[i][j] = min((min(dp[i-1][j-1],dp[i][j-1])),dp[i+1][j-1]) + a[i][j];
        }
    }
    ll ans = 1e9;
    for(int i = 1; i <= m; i++){
        ans = min(ans, dp[i][n]);
    }
    cout << ans << endl;;
}


int main(){
    cin >> t;
    while(t--){
        solve();
    }
}
