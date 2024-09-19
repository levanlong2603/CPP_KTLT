#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool cmp(string a, string b){
    return a > b;
}

int main(){
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<string> v;
        for(int i = 0; i < n; i++){
            string s; cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end(), cmp);
        for(auto x : v) cout << x;
        cout << endl;
    }
    return 0;
}
