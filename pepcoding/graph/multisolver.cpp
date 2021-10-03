#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int src;
    int nbr;
    int weight;
};

Edge make_edge(int u, int v,int w){
    Edge e;
    e.src=u;
    e.nbr=v;
    e.weight=w;
    return e;
}

struct Pair{
    string psf;
    int wsf;
};

Pair make_pair(string cpsf,int cwsf){
    Pair p;
    p.psf=cpsf;
    p.wsf=cwsf;
    return p;
} 

struct comp{
    bool operator()(Pair &a, Pair &b){
        return a.wsf>b.wsf;
    }    
};

int large_wt=INT_MIN;
string large_path="";
int small_wt=INT_MAX;
string small_path="";
int ceil_cri_wt=INT_MAX;
string ceil_cri_path="";
int floor_cri_wt=INT_MIN;
string floor_cri_path="";
priority_queue<Pair, vector<Pair>, comp> pq;

void dfs(vector<Edge> adj[],int src,int dst, string psf, int wsf,int cri,int k,bool vis[]){
    if(src==dst){
        if(wsf>large_wt){
            large_wt=wsf;
            large_path=psf;
        }
        if(wsf<small_wt){
            small_wt=wsf;
            small_path=psf;
        }
        if(wsf>cri && wsf<ceil_cri_wt){
            ceil_cri_wt=wsf;
            ceil_cri_path=psf;
        }
        if(wsf<cri && wsf>floor_cri_wt){
            floor_cri_wt=wsf;
            floor_cri_path=psf;
        }
        
        if(pq.size()<k){
            pq.push(make_pair(psf,wsf));
        }
        else{
            if(wsf>pq.top().wsf){
                pq.pop();
                pq.push(make_pair(psf,wsf));
            }
        }
        return;
    }
    
    vis[src]=true;
    for(Edge e:adj[src]){
        if(vis[e.nbr]==false)
            dfs(adj,e.nbr,dst,psf+to_string(e.nbr),wsf+e.weight,cri,k,vis);
    }
    vis[src]=false;
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
    int s,d;
    cin>>s>>d;
    int pwt;
    cin>>pwt;
    int k;
    cin>>k;
    dfs(adj,s,d,""+to_string(s),0,pwt,k,vis);
    
    cout<<"Smallest Path = "<<small_path<<"@"<<small_wt<<endl;
    cout<<"Largest Path = "<<large_path<<"@"<<large_wt<<endl;
    cout<<"Just Larger Path than "<<pwt<<" = "<<ceil_cri_path<<"@"<<ceil_cri_wt<<endl;
    cout<<"Just Smaller Path than "<<pwt<<" = "<<floor_cri_path<<"@"<<floor_cri_wt<<endl;
    cout<<k<<"th"<<" largest path = "<<pq.top().psf<<"@"<<pq.top().wsf<<endl;
    
    return 0;
}

// Smallest Path = 01256@28
// Largest Path = 032546@66
// Just Larger Path than 30 = 012546@36
// Just Smaller Path than 30 = 01256@28
// 4th largest path = 03456@48