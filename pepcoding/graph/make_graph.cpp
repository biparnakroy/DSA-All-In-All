#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int src;
    int nbr;
    int weight;
};

Edge make_edge(int src, int nbr, int weight){
    Edge e;
    e.src = src;
    e.nbr = nbr;
    e.weight = weight;

    return e;
}

int main(){
    int v, e;
    cin>>v>>e;
    //making the adjacency list of graph
    vector<Edge> adj[v];
    for(int i=0; i<e; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_edge(u,v,w));
        adj[v].push_back(make_edge(v,u,w));
    }
    //printing the adjacency list of graph
    for(int i=0;i<v;i++){
        //line 31 not required but achha dekhna hai 
        cout<<adj[i][0].src<<" -> ";
       for(Edge edge:adj[i]){
           cout<<"["<<edge.src<<" "<<edge.nbr<<" "<<edge.weight<<"] ";
       }
        cout<<endl;
    }
    return 0;
}