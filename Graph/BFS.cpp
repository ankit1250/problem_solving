#include"bits/stdc++.h"
using namespace std;

void BFS(vector<int> g[],int start,bool vis[]){
    queue<int> q;
    q.push(start);
    vis[start]=true;
    while(!q.empty()){
        int curr = q.front();
        cout<<curr<<" ";
        q.pop();
        for(int i=0;i<g[curr].size();i++){
            if(!vis[g[curr][i]]){
                q.push(g[curr][i]);
                vis[g[curr][i]]=true;
            }
        }
    }
}
int main(){
    int N,E;
    cin>>N>>E;
    vector<int> adj[N];
    bool visited[N];
    memset(visited,false,sizeof(visited));
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    BFS(adj,0,visited);
}