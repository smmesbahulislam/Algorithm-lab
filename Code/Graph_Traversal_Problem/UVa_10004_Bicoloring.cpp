#include<bits/stdc++.h>
using namespace std;

#define mx 1001

bool vis[mx];
bool color[mx];

vector<int>graph[mx];

void bfs(int nodes,int src)
{
    for(int i = 0;i < nodes;i++){
        color[i] = false;
        vis[i] = false;
    }

    queue<int>Q;
    Q.push(src);
    vis[src] = 1;

    while(!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        for(int i = 0;i < graph[node].size();i++)
        {
            int next = graph[node][i];
            if(vis[next] == 0)
            {
                vis[next] = 1;
                color[next] = !color[node];
                Q.push(next);
            }

            if(color[next] == color[node])
            {
                cout << "NOT ";
                return;
            }
        }
    }
    return;

}

int main()
{
    int nodes,edges,u,v;
    while(scanf("%d",&nodes) && nodes != 0)
    {
        cin >> edges;
        for(int i = 0;i < nodes;i++) graph[i].clear();
        for(int i = 0;i < edges;i++)
        {
            scanf("%d %d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        bfs(nodes,0);

        cout << "BICOLORABLE" << endl;
    }
    return 0;
}