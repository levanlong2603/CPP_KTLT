#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = 100001;
int n, m, s, t;
vector<pair<int, int>> adj[maxn];

void nhap(){
	cin >> n >> m >> s >> t;
	for(int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		adj[x].push_back({y, w});
	}
}

const int INF = 1e9;
int pre[maxn];

void dijkstra(int s, int t){
	//Mang luu khoang cach duong di
	vector<ll> d(n + 1, INF);
	d[s] = 0;
    pre[s] = s;
	priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int,int>>> Q;
	//{khoang cach, dinh}
	Q.push({0, s});
	while(!Q.empty()){
		//Chọn ra đỉnh có khoảng cách từ s nhỏ nhất 
		pair<int, int> top = Q.top(); Q.pop();
		int u = top.second;
		int kc = top.first;
		if(kc > d[u]) continue;
		//Relaxtion : Thông qua đỉnh u đã biết khoảng cách ngắn nhất tính từ S, cập
		//nhật khoảng cách với các đỉnh kề với u
		for(auto it : adj[u]){
			int v = it.first;
			int w = it.second;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				Q.push({d[v], v});
                pre[v] = u; // trước là u
			}
		}
	}
	cout << d[t] << endl;
    vector<int> path;
    while(1){
        path.push_back(t);
        if(t == s) break;
        t = pre[t];
    }
    reverse(begin(path), end(path));
    for(int x : path){
        cout << x << " ";
    }
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	nhap();
	dijkstra(s, t);
}
