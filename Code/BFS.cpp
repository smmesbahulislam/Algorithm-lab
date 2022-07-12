#include<bits/stdc++.h>
using namespace std;

#define mx 110

vector<int> graph[mx];
bool vis[mx];
int dis[mx];

void bfs(int source)
{
    queue<int>Q;
    vis[source] = 1;
    dis[source] = 0;
    Q.push(source);

    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop();

        for(int i = 0;i < graph[node].size();i++)
        {
            int next = graph[node][i];
            if(vis[next] == 0){
                vis[next] = 1;
                dis[next] = dis[node] + 1;
                Q.push(next);
            }
        }
    }

}

int main()
{
    int nodes,edges;
    cin >> nodes >> edges;

    for(int i = 1;i <= edges;i++)
    {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);

    }
    int source;
    cin >> source;

    bfs(source);

    cout << "From node " << source << endl;
    for(int i = 1;i <= nodes;i++)
    {
        cout << "Distance of " << i << " is : " << dis[i] << endl;
    }

    return 0;
}