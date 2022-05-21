#include<bits/stdc++.h>
using namespace std;

class graph{
    int V;
    list<int> *adj;//list<int> *table means that table is a pointer to a list<int>.
    // That is, the type of *table is list<int>
    void fillOrder(int s,bool visitedV[],stack<int> &Stack);
    void DFS(int s,bool visitedV[]);

    public:
    graph(int V);
    void addEdge(int s,int d);
    void printSSC();
    graph transpose(); 
};

graph::graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

//DFS
void graph::DFS(int s,bool visitedV[]){
    visitedV[s] = true;
    cout << s << " ";

    list<int> :: iterator it;
    for(it = adj[s].begin();it != adj[s].end();it++){
        if(!visitedV[*it]){
            DFS(*it,visitedV);
        }
    }
}

//Transpose
graph graph::transpose(){
    graph g(V);
    for(int s = 0; s < V;s++){
        list<int> :: iterator it;
        for(it = adj[s].begin();it != adj[s].end();++it){
            g.adj[*it].push_back(s);
        }
    }
    return g;
}

//add edge into the graph
void graph::addEdge(int s,int d){
    adj[s].push_back(d);
}

void graph::fillOrder(int s,bool visitedV[],stack<int>&Stack){
    visitedV[s] = true;
    list<int>::iterator it;
    for(it = adj[s].begin();it != adj[s].end();++it){
        if(!visitedV[*it]){
            fillOrder(*it,visitedV,Stack);
        }
    }
    Stack.push(s);
}

//Print SSC
void graph::printSSC(){
    stack<int> Stack;
    // bool *visitedV = new bool[V];
    bool visitedV[V];
    for(int i = 0;i < V;i++){
        visitedV[i] = false;
    }

    for(int i = 0;i < V;i++)
    {
        if(visitedV[i] == false)
            fillOrder(i,visitedV,Stack);
    }
    graph gr = transpose();
    for(int i = 0;i < V;i++)
    {
        visitedV[i] = false;
    }
    while(!Stack.empty()){
        int s = Stack.top();
        Stack.pop();
        if(visitedV[s]== false){
            gr.DFS(s,visitedV);
            cout << endl;
        }
    }
}

int main()
{
    int nodes,edges;
    cin >> nodes >> edges;
    graph g(nodes);
    for(int i = 0;i < edges;i++)
    {
        int x,y;
        cin >> x >> y;
        g.addEdge(x,y);
    }

    cout <<"Strongly Connected Components: \n";
    g.printSSC();
}