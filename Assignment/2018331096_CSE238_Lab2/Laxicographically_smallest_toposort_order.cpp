#include <bits/stdc++.h>
using namespace std;

vector<int> t;
int visit[10000] = {0};


void dfs(vector<int> adj[],int n)
{
    if(visit[n]==0)
    {
        visit[n]=1;
        for(int i=0;i<adj[n].size();i++)
        {
            dfs(adj,adj[n][i]);
        }
        t.push_back(n);
    }
}




int main()
{
    int n;
    cin>>n;
    vector<int> adj[n+1];

    int m;
    cin>>m;
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
    }

    for(int i=0;i<=n;i++)
    {
        sort(adj[i].begin(),adj[i].end(),greater<int>());
    }

    for(int j=n;j>=1;j--)
    {
        if(visit[j]==0)
        {
            dfs(adj,j);
        }
    }

// for(int j=t.size()-1;j>=0;j--)
// {
//     cout<<t[j]<<" ";
// }
    reverse(t.begin(),t.end());
    cout << "Laxicographically smallest toposort order: ";
    for(int i = 0;i < t.size();i++){
        cout << t[i] << ' ';
    }
    cout << endl;


    return 0;
}