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
#define NIL -1

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

class Graph
{
	int V; 
	list<int> *adj; 

    void SCCUtil(int u, int disc[], int low[],
				stack<int> *st, bool stackMember[]);
public:
	Graph(int V); 
	void addEdge(int v, int w);
	void SCC();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}


void Graph::SCCUtil(int u, int disc[], int low[], stack<int> *st,
					bool stackMember[])
{

	static int time = 0;

	disc[u] = low[u] = ++time;
	st->push(u);
	stackMember[u] = true;

	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		int v = *i; 

		if (disc[v] == -1)
		{
			SCCUtil(v, disc, low, st, stackMember);

			low[u] = min(low[u], low[v]);
		}

		
		else if (stackMember[v] == true)
			low[u] = min(low[u], disc[v]);
	}

	int w = 0; 
	if (low[u] == disc[u])
	{
		while (st->top() != u)
		{
			w = (int) st->top();
			cout << w << " ";
			stackMember[w] = false;
			st->pop();
		}
		w = (int) st->top();
		cout << w << "\n";
		stackMember[w] = false;
		st->pop();
	}
}

void Graph::SCC()
{
	int *disc = new int[V];
	int *low = new int[V];
	bool *stackMember = new bool[V];
	stack<int> *st = new stack<int>();

	for (int i = 0; i < V; i++)
	{
		disc[i] = NIL;
		low[i] = NIL;
		stackMember[i] = false;
	}

	for (int i = 0; i < V; i++)
		if (disc[i] == NIL)
			SCCUtil(i, disc, low, st, stackMember);
}

int main()
{
	cout << "\nSCCs in first graph \n";
	int n,m;
    cin>>n;
    Graph g1(n);
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        g1.addEdge(a,b);
    }
	g1.SCC();
	return 0;
}