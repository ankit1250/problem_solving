

#include <bits/stdc++.h>
#include<list>
using namespace std;

class Graph
{
       int V;
       list<int> *adj;
    public:
       Graph(int V);

       void addEdge(int v,int w);

       void BFS(int s);
    
};

Graph::Graph(int V){
    this->V= V;
    adj= new list<int>[V];
}


void Graph::addEdge(int v,int w){
    adj[v].push_back(w);
}

void Graph::BFS(int s){
    bool *visited= new bool[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }

    list<int> queue;
    visited[s]= true;

    list<int>:: iterator it;

    while (!queue.empty())
    {
        s= queue.front();
        cout<<s<<" ";

        queue.pop_front();
        for(it= adj[s].begin();it!=adj[s].end();it++){
            if(!visited[*it]){
                visited[*it]= true;
                queue.push_back(*it);
            }
        }
    }
    
}

int main(){
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}
