//Incomplete code :)

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9+10;

vector<pair<int,int> > g[N];
int par[N];

bool dijkstra(int source,int n)
{
    vector<int>vis(N,0);
    vector<int>dist(N,INF);

    set<pair<int,int> > st;

    st.insert({0,source});
    dist[source] = 0;
    par[source] = -1;

    while(st.size() > 0)
    {
        auto node = *st.begin();
        int v = node.second;
        int v_dist = node.first;
        st.erase(st.begin());

        if(v == n) return true;

        vis[v] = 1;
        for(auto child: g[v])
        {
            int child_v = child.first;
            int wt = child.second;

            if(!vis[child_v] && dist[v] + wt < dist[child_v])
            {
                st.erase({dist[child_v],child_v});
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v],child_v});
                par[child_v] = v;
            }
        }
    }
    return false;
}

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < m;i++)
    {
        int x,y,wt;
        cin >> x >> y >> wt;
        g[x].push_back({y,wt});
    }

    if(dijkstra(1,n))
    {
        vector<int>path;
        for(int v = n;v != -1;v = par[v]) path.push_back(v);

        for(int i = path.size() - 1;i > 0;--i) cout << path[i] << " " ;

        cout << path[0] << endl;

    }
    else
        puts("-1");

    return 0;
}