#include <bits/stdc++.h>
using namespace std;

int n, x[100], cnt;
bool cot[100], nguoc[100], xuoi[100];


void Try(int i){
    for(int j = n; j >= 1; j--){
        if(cot[j] == false && xuoi[i-j+ n] == false && nguoc[i + j - 1] == false){
            x[j] = j;
            cot[j] = true;
            xuoi[i-j+n] = true;
            nguoc[i + j - 1] = true;
            if(i == n) cnt++;
            else Try(i+ 1);
            cot[j] = false;
            xuoi[i-j+n] = false;
            nguoc[i + j - 1] = false;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        memset(cot, false, sizeof(cot));
        memset(nguoc, false, sizeof(nguoc));
        memset(xuoi, false, sizeof(xuoi));
        cin >> n;
        cnt = 0;
        Try(1);
        cout << cnt << endl;
    }
}
