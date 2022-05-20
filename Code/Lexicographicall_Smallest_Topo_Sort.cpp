#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
vector<int>indeg(1000,0);

void topologicalSort(int n){

    multiset<int> s;
    for(int i = 0;i < n;i++){
        if(indeg[i] == 0)
            s.insert(i);
    }


    int cnt = 0;
    vector<int>top_order;

    while(!s.empty()){
        int u = *s.begin();
        s.erase(s.begin());
        top_order.push_back(u);

        for(auto x: adj[u]){
            indeg[x]--;
            if(indeg[x] == 0)
                s.insert(x);
        }
        cnt++;
    }
    if(cnt != n){
        cout << "Topological Sorting is not possible!!" << endl;
        return;
    }
    for(int i = 0;i < top_order.size();i++){
        cout << top_order[i] << " ";
    }
    indeg.clear();
    adj.clear();
}

int main(){
    int nodes,edges;
    cin >> nodes >> edges;

    adj = vector<vector<int> > (nodes);

    for(int i = 0;i < edges;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    topologicalSort(nodes);
}