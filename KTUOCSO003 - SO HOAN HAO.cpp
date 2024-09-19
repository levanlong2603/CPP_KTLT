#include<bits/stdc++.h>
using namespace std;

using ll=long long;
int main(){
	int t; cin>>t;
	while(t--){
	int n; cin>>n;
	ll sum=0;
	for(int i=1; i<=sqrt(n); i++){
		if(n%i==0){
			sum+=i;
			if(i!=n/i){
				sum+=n/i;
		}
	}
}
		if(sum-n==n){
			cout<<"1"<<endl;
		}
		else cout <<"0"<<endl;
		}
}
