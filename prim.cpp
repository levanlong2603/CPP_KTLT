#include <bits/stdc++.h>
using namespace std;

struct canh{
    int x, y , w;
};

const int maxn = 100001;
int n, m, s, t;
vector<pair<int, int>> adj[maxn]; 
bool use[maxn];

void nhap(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
            int w; cin >> w;
            if(w){
                adj[i].push_back({j, w});
                adj[j].push_back({i, w});
            }
        }
	}
    memset(use, false, sizeof(use));
}

void prim(int u){
    vector<canh> Mst;
    int d = 0;
    use[u] = true;
    while(Mst.size() < n - 1){
        int min_w = INT_MAX;
        int x, y;
        for(int i = 1; i <= n; i++){
            if(use[i]){
                for(pair<int,int> it : adj[i]){
                    int j = it.first, trongso = it.second;
                    if(!use[j] && trongso < min_w){
                        min_w = trongso;
                        x = j; y = i;
                    }
                }
            }
        }
        Mst.push_back({x, y, min_w});
        d += min_w;
        use[x] = true;
    }
    cout << d << endl;
    for(canh e : Mst){
        cout << e.x << ' ' << e.y << ' ' << e.w << endl;
    }
}

int main(){
    nhap();
    prim(1);
}
