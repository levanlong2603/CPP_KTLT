#include <bits/stdc++.h>
using namespace std;

int uocso(int n){
	int sum=0;
    for(int i=1; i<=sqrt(n); i++){
        if(n%i==0){
            sum+=i;
            if(i!=n/i){
                sum+=n/i;
            }
        }
    }
    return sum-n;
}
int main(){
	int t; cin>>t;
	while(t--){
		int a, b; cin>>a>>b;
		if(uocso(a)==b && uocso(b)==a)
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

