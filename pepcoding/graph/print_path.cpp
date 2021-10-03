#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int src;
    int nbr;
    int weight;
};


Edge make_edge(int src, int nbr, int weigh){
    Edge e;
    e.src=src;
    e.nbr=nbr;
    e.weight=weigh;

    return e;
}
void print_all_paths(vector<Edge>adj[],int src, int dst, bool vis[],string psf){
    if(src==dst){
        cout<<psf<<endl;
        return;
    }
    vis[src]=true;
    for(Edge edge:adj[src]){
        if(!vis[edge.nbr]){
            print_all_paths(adj,edge.nbr,dst,vis,psf+to_string(edge.nbr));
        }
    }
    vis[src]=false;
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<Edge> adj[v];
    bool vis[v];
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_edge(u,v,w));
        adj[v].push_back(make_edge(v,u,w));
    }
    int s,d;
    cin>>s>>d;
    print_all_paths(adj,s,d,vis,""+to_string(s));
    return 0;
}