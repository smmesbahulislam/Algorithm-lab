#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;
vector<int> indeg;
vector<bool>vis;
list<int>path;

void printPath(list<int>order){
    while(!order.empty()){
        cout << order.front() << " ";
        order.pop_front();
    }
    cout << endl;
}

void findAllTopologicalSort(int vertex){
    for(int v = 1;v <= vertex;v++)
    {
        if(indeg[v] == 0 && !vis[v])
        {
            path.push_back(v);
            vis[v] = true;
            for(auto x:graph[v]){
                indeg[x]--;
            }

            findAllTopologicalSort(vertex);
        
            //Backtracking:
            for(auto x:graph[v]){
                indeg[x]++;
            }
            path.pop_back();
            vis[v] = false;
        }
    }

    if(path.size() == vertex){
        printPath(path);
    }
}



int main(){
    int nodes,edges;
    cin >> nodes >> edges;
    graph = vector<vector<int> > (nodes+1);
    indeg = vector<int> (nodes+1);
    vis = vector<bool> (nodes,false);
    for(int i = 0;i < edges;i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        indeg[v]++;
    }
    findAllTopologicalSort(nodes);

}
