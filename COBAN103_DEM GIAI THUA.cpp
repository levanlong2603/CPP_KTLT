#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll a[100001];
int cnt[10007];

void ktao(){
    ll m = 1, q, r = 0;
    a[0] = 1;
    cnt[0] = cnt[1] = 1;
    for(int i = 2; i <= 10000; i++){
        for(int j = 0; j < m; j++){
            q = a[j] * i + r;
            a[j] = q % 10;
            r = q / 10;
        }
        while(r > 0){
            a[m] = r % 10;
            m++;
            r /= 10;
        }
        cnt[i] = m;
    }
}

int main(){
    ktao();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> x;
        for(int i = 0; i <= 1000; i++){
            if(cnt[i] > n) break;
            else if(cnt[i] == n){
                x.push_back(i);
            }
        }
        if(x.size() == 0) cout << "NO";
        else {
            cout << x.size() << " ";
            for(int v : x) cout << v << " ";
        }
        cout << endl;
    }
}
