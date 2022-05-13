//JUDGE_ID: 323675HR
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define lld long long double
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vll vector<ll,ll>
#define mii map<int,int>
#define mod 1e9+7
#define fl(i,n) for(int i = 0;i < n;i++)
#define nl '\n'
#define MAX_N 20001

int n,m;

void setIO()
{
    faster
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
}

// void solve()
// {
    
//     return;
// }


struct Node
{
    vector<int> adj;
    vector<int> rev_adj;
};

Node g[MAX_N];

stack<int> S;
bool visited[MAX_N];

int component[MAX_N];
vector<int> components[MAX_N];
int numComponents;

void dfs_1(int x)
{
    visited[x] = true;
    for (int i = 0; i < g[x].adj.size(); i++)
        if (!visited[g[x].adj[i]])
            dfs_1(g[x].adj[i]);

    S.push(x);
}

void dfs_2(int x)
{
    printf("%d ", x);
    component[x] = numComponents;
    components[numComponents].push_back(x);
    visited[x] = true;
    for (int i = 0; i < g[x].rev_adj.size(); i++)
    {
        if (!visited[g[x].rev_adj[i]])
            dfs_2(g[x].rev_adj[i]);
    }
}

void Kosaraju()
{
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs_1(i);

    for (int i = 0; i < n; i++)
        visited[i] = false;

    while (!S.empty())
    {
        int v = S.top();
        S.pop();
        if (!visited[v])
        {
            printf("Component %d: ", numComponents);
            dfs_2(v);
            numComponents++;
            printf("\n");
        }
    }
}

int main()
{
    cin >> n >> m;
    int a, b;
    while (m--)
    {
        cin >> a >> b;
        g[a].adj.push_back(b);
        g[b].rev_adj.push_back(a);
    }
    Kosaraju();
    printf("Total number of components: %d\n", numComponents);

    return 0;
}