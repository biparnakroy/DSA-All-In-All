#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src;
    int nbr;
    int weight;
};

Edge make_edge(int src, int nbr, int weight) {
    Edge e;
    e.src = src;
    e.nbr = nbr;
    e.weight = weight;

    return e;
}
bool hasPath(vector<Edge> adj[],int src, int dst, bool vis[]){
    if(src == dst)
        return true;
    vis[src] = true;
    for(Edge edge: adj[src]){
        if(vis[edge.nbr]==false){
            bool hasNbrPath = hasPath(adj,edge.nbr,dst,vis);

            if(hasNbrPath)
                return true;
        }
    }
    return false;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<Edge> adj[v];
    bool vis[v];
    memset(vis, false, sizeof(vis));

    for (int i = 0; i < e; i++) {
        int src, nbr, weight;
        cin >> src >> nbr >> weight;
        adj[src].push_back(make_edge(src, nbr, weight));
        adj[nbr].push_back(make_edge(nbr, src, weight));
    }
    int s, d;
    cin >> s >> d;

    bool Path = hasPath(adj, s, d, vis);
    if (Path)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}
