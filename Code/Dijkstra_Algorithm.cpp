#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int INF = 1e9+10;


vector<pair<int,int> > g[N];

void dijkstra(int source,int n){
    vector<int> vis(N,0);
    vector<int> dist(N,INF);
    

    set<pair<int,int> > st;

    st.insert({0,source});
    dist[source] = 0;

    while(st.size() > 0){
        auto node = *st.begin();
        int v = node.second;
        int v_dist = node.first;
        st.erase(st.begin());
        if(vis[v] == 1) continue;

        vis[v] = 1;
        for(auto child: g[v]){
            int child_v = child.first;
            int wt = child.second;
            if(dist[v] + wt < dist[child_v]){
                st.erase({dist[child_v],child_v});
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }

    for(int i = 1;i <= n;i++){
        if(dist[i] < INF){
            cout << dist[i] << " ";
        }
        else{
            cout << -1 << " ";
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int x,y,wt;
        cin >> x >> y >> wt;
        g[x].push_back({y,wt});
        g[y].push_back({x,wt});
    }

    int source;
    cin >> source;
    dijkstra(source,n);

    return 0;
}