#include "bits/stdc++.h"
using namespace std;

void dfs(vector<int> g[],int start,bool *vis){
    vis[start]=true;
    cout<<start<<" ";
    for(int i=0;i<g[start].size();i++){
        if(vis[g[start][i]] == false){
            dfs(g,g[start][i],vis);
        }
    }
}


int main(){
    int N,E;
    cin>>N>>E;
    vector<int> g[N];
    bool visited[N];
    memset(visited,false,sizeof(visited));
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(g,0,visited);

}
