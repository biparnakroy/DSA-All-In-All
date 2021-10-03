#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int src;
    int nbr;
    int wt;
};

Edge make_edge(int u,int v, int w){
    Edge e;
    e.src=u;
    e.nbr=v;
    e.wt=w;
    return e;
}
void dfs(vector<Edge> adj[],int s,bool vis[],vector<int> &comp){
    vis[s]=true;
    comp.push_back(s);
    for(Edge e:adj[s]){
        if(vis[e.nbr]==false)
            dfs(adj,e.nbr,vis,comp);
    }
}
int main(){
    int v,e;
    cin>>v>>e;
    vector<Edge>adj[v];
    bool vis[v];
    memset(vis, false, sizeof(vis));
    
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_edge(u,v,w));
        adj[v].push_back(make_edge(v,u,w));
    }
    vector< vector<int>> comps;
    for(int i=0;i<v;i++){
        
        if(vis[i]==false){
            vector<int>comp;
            dfs(adj,i,vis,comp);
            comps.push_back(comp);
        }
        
    }
    cout<<"[";
    for(int i=0;i<comps.size();i++){
        cout<<"[";
        for(int j=0;j<comps[i].size();j++){
            cout<<comps[i][j];
            if(j!=comps[i].size()-1)
                cout<<", ";
        }
        if(i!=comps.size()-1)
        cout<<"], ";
        else
        cout<<"]";
    }
    cout<<"]";
    return 0;
}