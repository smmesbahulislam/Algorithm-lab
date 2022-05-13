#include<bits/stdc++.h>
using namespace std;

//here maxD represent the diameter of the tree
int maxD = -1,maxNode = -1;
//maxNode represents node at maximum distance

//declaring the visited node as we will be using the DFS
int vis[8];

// void createEdge(int a,int b,vector<int> graph[]){
//     //creating undirected edges between the connected nodes
//     graph[a].push_back(b);
//     graph[b].push_back(a);
// }

void DFS(vector<int>graph[],int node,int d){
    //making the node as visited
    vis[node] = 1;

    /*
    if the distance from root is greater then maximum
    Distance then updating the maximum value of distance.
    Also storing the maxNode no. as this node is now at the 
    farthest distance.

    */

   if(d > maxD){
       maxNode = node;
       maxD = d;
   }

   //applying the standard dfs

   for(auto x: graph[node]){
       if(vis[x] == 0){
           DFS(graph,x,d+1);
       }
   }
}

int main(){
    int nodes;
    cin >> nodes;
    //first creating the nodes of the graph
    vector<int> graph[nodes];

    //now creating the edges of the tree as shown in the image 
    for(int i = 1,u,v;i < nodes-1;i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    //applying DFS from node 1
    DFS(graph,1,1);
    //we could have choosen any node in the graph.

    //making everynode unvisited as we will be applying DFS
    maxD = -1;
    for(int i = 1;i <= nodes;i++){
        vis[i] = 0;
    }

    //applying the dfs for the second time as this will give the
    //diameter of the tree;
    DFS(graph,maxNode,1);


    cout << maxD << " is the diameter of the tree"<<endl;

    return 0;


}