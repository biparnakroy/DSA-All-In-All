#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int src;
    int nbr;
    int weight;
};

Edge make_edge(int u,int v, int w){
    Edge e;
    e.src=u;
    e.nbr=v;
    e.weight=w;
    return e;
}

void dfs(vector<Edge> adj[],int s,bool vis[]){
    vis[s]=true;
    for(Edge e:adj[s]){
        if(vis[e.nbr]==false)
            dfs(adj,e.nbr,vis);
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<Edge> adj[v];
    bool vis[v];
    memset(vis,false,sizeof(vis));
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_edge(u,v,w));
        adj[v].push_back(make_edge(v,u,w));
    }
    int count=0;
    
    for(int i=0;i<v;i++){
        if(vis[i]==false){
            dfs(adj,i,vis);
            count++;
        }
    }
    
    if(count==1)
        cout<<"true"<<endl;
    else if(count>1)
        cout<<"false"<<endl;
    
    return 0;
}