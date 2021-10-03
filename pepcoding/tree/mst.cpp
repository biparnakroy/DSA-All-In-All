#include <bits/stdc++.h>
using namespace std;

struct Connection{
    int firstTown;
    int secondTown;
    int cost;
    
    Connection (int n, int m, int wt ){
        firstTown=n;
        secondTown=m;
        cost=wt;
    }
};

struct comp{
    bool operator()(Connection const &A, Connection const &B)
    {
        return A.cost>B.cost? true:false;
    }
};
 
int main(){
    
    int ver,edg;
    cin>>ver>>edg;
    
    vector<Connection>adj[ver];
    
    for(int i=0;i<edg;i++){
        
        int n1,n2,wt;
        cin>>n1>>n2>>wt;
        Connection cn1(n1,n2,wt);
        Connection cn2(n2,n1,wt);
        adj[n1].push_back(cn1);
        adj[n2].push_back(cn2);
        
    }
    
    priority_queue<Connection,vector<Connection>, comp> q;
    Connection initial(0,-1,0);
    q.push(initial);
    
    bool vis[ver+1];
    memset(vis,false,sizeof(vis));
    
    while(!q.empty()){
        Connection current= q.top();
        q.pop();
        
        if(vis[current.firstTown]==true)
            continue;

        vis[current.firstTown]==true;
        
        if(current.secondTown!=-1)
            cout<<"["<<current.firstTown<<"-"<<current.secondTown<<"@"<<current.cost<<"]"<<endl;
        
        for(Connection e : adj[current.firstTown]){
           if(vis[e.secondTown]==false){
               Connection now(e.secondTown, current.firstTown,e.cost);
               q.push(now);
           }
        }
    }
    
    
    return 0;
}

// 7
// 8
// 0 1 10
// 1 2 10
// 2 3 10
// 0 3 40
// 3 4 2
// 4 5 3
// 5 6 3
// 4 6 8

// [1-0@10]
// [2-1@10]
// [3-2@10]
// [4-3@2]
// [5-4@3]
// [6-5@3]