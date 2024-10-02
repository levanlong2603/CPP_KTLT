#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n, m , c[505][105], x[500];
int visited[505];
int d = 0, ans = INT_MAX;
int cmin = INT_MAX;

void nhap(){
    cin >> n >> m;
    int i , j ,a;
    while(m--){
        cin >> i >> j >> a;
        c[i][j] = a;
        cmin = min(cmin, a);
    }
    memset(visited, 0, sizeof(visited));
}

void Try(int i){
    for(int j = 2; j <= n; j++){
        if(visited[j] == 0 && c[x[i-1]][j] != 0){
            x[i] = j;
            d += c[x[i-1]][x[i]];
            visited[j] = 1;
            if(i == n){
                if(c[x[i]][1])ans = min(ans, d + c[x[i]][1]);
            }
            else if(d + (n - i + 1)* cmin < ans){
                Try(i + 1);
            }
            visited[j] = 0;
            d -= c[x[i-1]][x[i]];
        }
    }
}

int main(){
    nhap();
    x[1] = 1;
    visited[1] = 1;
    Try(2);
    cout << ans;
}
