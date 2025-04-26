#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i < (n);i++)
#define rep1(i,n) for (int i=1;i <= (n);i++)
using ll=long long;
#include<atcoder/all>
using namespace atcoder;
#define yn puts("Yes"); else puts("No");
void chmin(int& a, int b) { a=min(a,b); }
void chmax(int& a, int b) { a=max(a,b); }

struct Edge {
    int to;
    int cost;

    Edge() : to(-1), cost(-1){} // デフォルトコンストラクタ
    Edge(int to, int cost) : to(to), cost(cost) {}
};

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    int s,t;
    cin >> s >> t;
    s--; t--;
    vector<vector<Edge>> graph(n);
    rep(i,m) {
        int ui, vi, wi;
        cin >> ui >> vi >> wi;
        ui--; vi--;
        graph[ui].emplace_back(vi,wi);
    }

    const ll inf=1e18;
    vector<ll> dist(n,inf); //始点からの距離
    dist[s]=0; //始点

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> que; // 小さい順に取り出す
    que.emplace(0, s);

    while(!que.empty()) {
        auto [d,v] = que.top(); que.pop();
        if (dist[v] < d) continue;

        for (const Edge& e : graph[v]) {
            if (dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                que.emplace(dist[e.to], e.to);
            }
        }
    }

    if(dist[t] != inf) cout << "最短距離: " << dist[t] << endl;
    else cout << "到達不可能" << endl;

    return 0;
} 


