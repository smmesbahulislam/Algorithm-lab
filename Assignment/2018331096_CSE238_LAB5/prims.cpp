//Prim's algo in cpp

#include<bits/stdc++.h>

using namespace std;

#define INF 9999999

#define V 7

int G[V][V]={
    {0, 7, 0, 5, 0, 0, 0},
    {7, 0, 8, 9, 7, 0, 0},
    {0, 8, 0, 0, 5, 0, 0},
    {5, 9, 0, 0, 15, 6, 0},
    {0, 7, 5, 15, 0, 8, 9},
    {0, 0, 0, 6, 8, 0, 11},
    {0, 0, 0, 0, 9, 11, 0}
};


int main()
{
    int numEdge,TotalCost = 0;

    int vis[V];

    memset(vis, false, sizeof(vis));

    numEdge = 0;

    vis[0] = true;

    int row,col;
    cout << "Edge" << " : " << "Weight" << endl;

    while(numEdge < V-1){
        int min = INF;
        row = 0, col = 0;

        for(int i = 0;i < V;i++){
            if(vis[i]){
                for(int j = 0;j < V;j++){
                    if(!vis[j] && G[i][j]){
                        if(min > G[i][j]){
                            min = G[i][j];
                            row = i;
                            col = j;
                        }
                    }
                }
            }
        }
        cout << row << " - " << col << " : " << G[row][col] << endl;
        TotalCost += G[row][col];
        vis[col] = true;
        numEdge++;
    }
    cout << "Total Cost of MST : " << TotalCost << endl;
    return 0;
}