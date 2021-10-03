#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int src;
    int nbr;
    int weight;
};

Edge* make_edge(int src, int nbr, int weight){
    Edge* e = new Edge();
    e->src = src;
    e->nbr = nbr;
    e->weight = weight;

    return e;
}
int main(){
    int vertices,edges;
    cin>>vertices>>edges;

    vector<Edge*> adj[vertices];

    for(int i=0;i<edges;i++){
        int src,nbr,weight;
        cin>>src>>nbr>>weight;
        adj[src].push_back(make_edge(src,nbr,weight));
        adj[nbr].push_back(make_edge(nbr,src,weight));
    }

    for(int i=0;i<vertices;i++){
        cout<<"Vertex "<<i<<" : ";
        for(int j=0;j<adj[i].size();j++){
            cout<<"["<<adj[i][j]->src<<" "<<adj[i][j]->nbr<<" "<<adj[i][j]->weight<<"] ";
        }
        cout<<endl;
    }


    return 0;
}


// 7
// 8
// 0 1 10
// 1 2 10
// 2 3 10
// 0 3 10
// 3 4 10
// 4 5 10
// 5 6 10
// 4 6 10

// Vertex 0 : 1 3 
// Vertex 1 : 0 2 
// Vertex 2 : 1 3 
// Vertex 3 : 2 0 4 
// Vertex 4 : 3 5 6 
// Vertex 5 : 4 6 
// Vertex 6 : 5 4 