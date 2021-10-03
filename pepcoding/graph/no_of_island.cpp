#include <bits/stdc++.h>
using namespace std;

static int m=1000;
void dfs(int n,int m,int i,int j,int* adj){
    if( i<0 || j<0 || i>n-1 || j>m-1|| *(adj+i*m+j)==1||*(adj+i*m+j)==2)
        return;
        
    *(adj+i*m+j)=2;
    
    dfs(n,m,i-1,j,(int*)adj);
    dfs(n,m,i,j-1,(int*)adj);
    dfs(n,m,i,j+1,(int*)adj);
    dfs(n,m,i+1,j,(int*)adj);
}

int main(){
    int n,m;
    cin>>n>>m;
    int adj[n][m];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>adj[i][j];
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]==0){
                dfs(n,m,i,j,(int*) adj);
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}