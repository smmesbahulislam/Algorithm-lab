#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main(){
    int n,m;
    cin>> n >> m;
    vector<vector<int> > edges;
    for(int i = 0;i < m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }

    int src;
    cin >> src;
    vector<int> dis(n,INF);
    dis[src] = 0;
    for(int iter = 0;iter < n-1;iter++){
        for(auto e: edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            dis[v] = min(dis[v],w + dis[u]);
        }
    }
    for(auto i:dis){
        cout << i << " ";
    }
    cout << endl;
}