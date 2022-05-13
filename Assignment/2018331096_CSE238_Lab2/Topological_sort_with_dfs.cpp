#include<bits/stdc++.h>

using namespace std;
vector<int>graph[105];
bool vis[105];
vector<int>result;

void dfs(int source){
    vis[source] = 1;
    for(int i = 0;i < graph[source].size();i++){
        int next = graph[source][i];
        if(vis[next] == 0)
            dfs(next);
    }
    result.push_back(source);
}

int main()
{
    int nodes,edges;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for(int i = 1;i <= nodes;i++){
        if(vis[i] == 0)
            dfs(i);
    }
    reverse(result.begin(),result.end());
    cout << "Topological order: ";
    for(int i = 0;i < result.size();i++){
        cout << result[i] << ' ';
    }
    cout << endl;
    return 0;
}