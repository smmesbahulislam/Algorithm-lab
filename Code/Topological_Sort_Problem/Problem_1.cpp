// http://uva.onlinejudge.org/external/103/10305.html
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nodes, edges;
    while (scanf("%d %d", &nodes, &edges) == 2 && nodes != 0 && edges != 0)
    {
        vector<int> adj[nodes + 1];
        vector<int> indeg(nodes + 1, 0);

        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            indeg[v]++;
        }

        queue<int> q;
        for (int i = 1; i <= nodes; i++)
        {
            if (indeg[i] == 0)
                q.push(i);
        }

        // int cnt = 0;
        while (!q.empty())
        {
            // cnt++;
            int x = q.front();
            q.pop();

            cout << x << " ";
            for (auto it : adj[x])
            {
                indeg[it]--;
                if (indeg[it] == 0)
                    q.push(it);
            }
        }
        cout << endl;
    }
}
