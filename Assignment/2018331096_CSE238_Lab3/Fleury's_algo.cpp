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
#define sz 1000

bool graph[sz][sz];
int nodes,edges;
int deg[sz];
vector<pair<int,int> > eular;
bool vis[sz];
int cnt = 0;

void setIO()
{
    faster
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
}

void dfs(int source){
    vis[source] = 1;
    for(int i = 0;i < nodes;i++){
        if(graph[source][i] && !vis[i]){
            cnt++;
            dfs(i);
        }
    }
}
bool isBridge(int u,int v){
    dfs(u);
    int before = cnt;
    memset(vis,false,sizeof(vis));
    cnt = 0;

    graph[u][v] = false;
    graph[v][u] = false;
    dfs(u);
    int after = cnt ;
    memset(vis,false,sizeof(vis));
    cnt = 0;

    graph[u][v] = true;
    graph[v][u] = true;

    return after<before;
    
}
void doEularTraverse(int u){
    if(eular.size() == edges)
        return;
    int bridge;

    for(int v = 0;v < nodes;v++){
        if(!graph[u][v])
            continue;
        if(isBridge(u,v))
            bridge = v;
        else
        {
            graph[u][v] = false;
            graph[u][v] = false;
            eular.push_back({u,v});
            doEularTraverse(v);
            return;
        }
    }
    graph[u][bridge] = false;
    graph[bridge][u] = false;
    eular.pb({u,bridge});
    doEularTraverse(bridge);
    return;
}

int getSource()
{
    int odd = 0;
    int source = 0;

    for(int i = 0;i < nodes;i++)
    {
        if(deg[i]%2)
        {
            odd++;
            source = i;

        }
    }
    if(odd == 0 || odd == 2)
        return source;
    else
        return -1;
}

void findEularPath()
{
    int source = getSource();
    if(source == -1)
        cout << "No eular path" << nl;
    else
        doEularTraverse(source);
}



// void solve()
// {
    
//     return;
// }

int main()
{
    setIO();
    // int t;
    // cin >> t;
    // while(t--){
    //     solve();

    // }
    cin >> nodes >> edges;
    for(int i = 0;i < edges;i++)
    {
        int u,v;
        cin >> u >> v;
        graph[u][v] = true;
        graph[v][u] = true;
        deg[u]++;
        deg[v]++;
    }
    findEularPath();

    cout << "Eular Path : "<<endl;

    for(int i = 0;i < eular.size();i++)
        cout << eular[i].first << " " << eular[i].second << endl;


    return 0;
}