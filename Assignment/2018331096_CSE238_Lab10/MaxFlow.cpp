#include<bits/stdc++.h>
using namespace std;
#define nl '\n'

const int MXN = 1010;
const int inf = 1e9 + 7;

int capacity[MXN][MXN];
int N, E;

int visited[MXN], parent[MXN];


void dfs(int u)
{
    visited[u] = 1;
    for(int v=0; v<N; v++)
    {
        if(visited[v] || !capacity[u][v])
            continue;
        parent[v] = u;
        dfs(v);
    }
    return;
}


vector<int> findPath(int src, int dst)
{
    memset(visited, 0, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    dfs(src);

    vector<int>path;
    if(!visited[dst])
        return path;

    int node = dst;
    while(node!=-1)
    {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());
    return path;
}
int findFlow(int srce, int sink)
{
    int cap = 0;
    while(1)
    {
        vector<int>path = findPath(srce, sink);
        if(path.empty())
            return cap;
        
        int mn = INT_MAX;
        for(int i = 0; i<path.size()-1; i++)
            mn = min(mn, capacity[path[i]][path[i+1]]);
        for(int i = 0; i<path.size()-1; i++)
        { 
            capacity[path[i]][path[i+1]]-=mn;
            capacity[path[i+1]][path[i]]+=mn;
        }
        cap+=mn;
    }

}

int main()
{
    scanf("%d%d", &N,&E);
    memset(capacity, 0, sizeof(capacity));
    int a, b, w;
    while(E--){
        scanf("%d%d%d", &a, &b, &w);
        capacity[a][b] += w;
    }
    int srce, sink;

    scanf("%d%d", &srce, &sink);

    int flow = findFlow(srce, sink);

    cout<<flow<<endl;
    return 0;
}

/*
6 8
0 1 11
0 2 12
2 1 1
1 3 12
2 4 11
4 3 7
4 5 4
3 5 19
0 5

4 5
0 1 6
0 2 4
1 2 10
1 3 2
2 3 5
0 3

*/