#include <bits/stdc++.h>
using namespace std;

int n, x[100];
bool used[100];

void kq(){
    for(int i = 1; i <= n; i++){
        cout << x[i];
    }
    cout << endl;
}

void Try(int i){
    for(int j = n; j >= 1; j--){
        if(used[j] == false){
            x[i] = j;
            used[j] = true;
            if(i == n){
                kq();
            }
            else Try(i + 1);
            used[j] = false;
        }
    }
}

int main(){
    memset(used, false, sizeof(used));
    cin >> n;
    Try(1);
}
