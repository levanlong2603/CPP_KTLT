#include<bits/stdc++.h>
using namespace std;

string n;
int a, b;

void in1(){
	int x = n.size() / 2 + 1;
	for(int i = 0; i < x; i++){
		cout << a;
	}
	for(int i = 0; i < x; i++){
		cout << b;
	}
}

void in2(){
    vector<int> v;
    int x = n.size() / 2;
    int cnt1 = x, cnt2 = x;
    int i = 0;
    while((n[i] - '0') <= b && i < n.size()) i++;
    while((n[i] - '0') + 1 > b && i > 0) i--;
    n[i] = (b + '0');
    if(i == 0){
        cout << b; cnt2--;
        while(cnt1--) cout << a;
        while(cnt2--) cout << b;
    }
    else{
        for(int j = 0; j <= i; j++){
            int c = (n[j] - '0');
            if(a >= c && cnt1 > 0){
                v.push_back(a);
                cnt1--;
            }
            else if(c == b){
                v.push_back(b);
                cnt2--;
            }
            else if(c < b){
                v.push_back(b);
                cnt2--;
                break;
            }
        }
        while(cnt1--) v.push_back(a);
        while(cnt2--) v.push_back(b);
        for(int u : v){
            cout << u;
        } 
    }
}


int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		cin >> a >> b;
		if(a > b) swap(a, b);
		if(n.size() % 2 == 1){
			in1();
		}
		else{
			long long res = stoll(n);
			string s = "";
			for(int i = 0 ; i < n.size()/2; i++){
				s += (b + '0');
			}
			for(int i = 0 ; i < n.size()/2; i++){
				s += (a + '0');
			}
			long long ans = stoll(s);
			if(res > ans){
				in1();
			}
			else if(res == ans){
				cout << ans;
			}
			else{
                in2();
            }
        }
		cout << endl;
	}
    return 0;
}
