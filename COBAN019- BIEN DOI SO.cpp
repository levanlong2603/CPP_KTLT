#include <bits/stdc++.h>
using namespace std;

int cnt(int n){
    if(n <  2) return n;
    int x = sqrt(n);
    int ans = 1 + min(n % 2 + cnt(n/2), min(n % 3 + cnt(n/3), n - x*x + cnt(x)));
    return ans;
}

int main (){
	int t;
	cin >> t;
	while (t--){
		int n ;
		cin >> n;
		cout << cnt(n) << endl;
	}
	return 0;
}
