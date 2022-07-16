#include<bits/stdc++.h>
using namespace std;

vector<int>indeg;
vector<vector<int> > graph;
vector<bool> vis;
list < int > path;


void printPath(list<int>path)
{
    while(!path.empty())
    {
        cout << path.front() << " ";
        path.pop_front();
    }
    cout << endl;
}


void findAllTopoSort(int nodes)
{
    for(int i = 1;i <= nodes;i++)
    {
        if(indeg[i] == 0 && !vis[i])
        {
            path.push_back(i);
            vis[i] = true;
            for(auto x:graph[i])
            {
                indeg[x]--;
            }

            findAllTopoSort(nodes);

            //backtrack
            for(auto x: graph[i])
            {
                indeg[x]++;
            }
            path.pop_back();
            vis[i] = false;
        }
    }

    if(path.size() == nodes)
    {
        printPath(path);
    }
}

int main()
{
    int nodes,edges;
    cin >> nodes >> edges;

    graph = vector< vector<int> > (nodes + 1);
    indeg = vector<int> (nodes + 1,0);
    vis = vector<bool> (nodes,false);

    for(int i = 0;i < edges;i++)
    {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        indeg[v]++;
    }
    findAllTopoSort(nodes);
}