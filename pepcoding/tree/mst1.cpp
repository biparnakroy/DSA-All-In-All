#include<bits/stdc++.h>
using namespace std;

// my answer
class Edge{
    public:
    int src;
    int nbr;
    int wt;
    
    Edge(int src , int nbr , int wt){
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
    
};

class Pair{
    public:
    int v ; // vertex
    int av; // aquiring vertex
    int wt; // weight
    
    Pair(int v, int av, int wt){
        this->v = v;
        this->av = av;
        this->wt = wt;
    }
};

int main(){

      int vtces,edges;
      cin>>vtces>>edges;
      vector<Edge*>graph[vtces];
      for(int i = 0; i < edges; i++){
         int v1,v2,wt;
         cin>>v1>>v2>>wt;
         graph[v1].push_back(new Edge(v1, v2, wt));
         graph[v2].push_back(new Edge(v2, v1, wt));
      }


   auto cmp = [](Pair* a, Pair* b) { return a->wt > b->wt;};
   priority_queue<Pair*,vector<Pair*>,decltype(cmp)>pq(cmp);
   
    pq.push(new Pair(0,-1, 0));
    bool visited[vtces];   //={false} 
    
    for(int i=0;i< vtces;i++){
         visited[i]= false;
    }
    
    
    while(pq.size()>0){
         Pair* rem = pq.top();
         pq.pop();
         if(visited[rem->v] == true){
            continue;
         }
         visited[rem->v]=true;
         
         if(rem->av != -1){
             cout<<"["<<rem->v<<"-"<<rem->av<<"@"<<rem->wt<<"]"<<"\n";
         }
         
         for(Edge* e: graph[rem->v]){
             if(visited[e->nbr] == false){
                pq.push(new Pair(e->nbr , rem->v, e->wt));
             }
         }
    }
    
    return 0;
}