#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;

int main(){
	int n;
	cin >> n;
	int a[n];
	int f[n];
	memset(f, 1, sizeof(f));
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(a[i] > a[j]){
				f[i] = max(f[i], f[j]+1);
			}
		}
	}
	cout << *max_element(f, f + n) << endl;
}
