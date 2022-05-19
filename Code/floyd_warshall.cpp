#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;


int main(){
    int nodes,edges;
    cin >> nodes >> edges;


    vector<vector<int> > graph(nodes+1,vector<int>(nodes+1,INF));
    for(int i = 1;i <= edges;i++){
        int x,y,wt;
        cin >> x >> y >> wt;
        graph[x][y] = wt;
    }
    for(int i = 1;i <= nodes;i++){
        graph[i][i] = 0;
    }

    vector<vector<int> > dist = graph;
    for(int k = 1;k <= nodes;k++){
        for(int i = 1;i <= nodes;i++){
            for(int j = 1;j <= nodes;j++){
                dist[i][j] = min(dist[i][j],(dist[i][k]+dist[k][j]));
            }
        }
    }

    for(int i = 1;i <= nodes;i++){
        for(int j = 1;j <= nodes;j++){
            if(dist[i][j] == INF){
                cout << "INF " ;
            }
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}