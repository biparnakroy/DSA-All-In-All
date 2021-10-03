#include <bits/stdc++.h>
using namespace std;

static int m=1000;

void dfs_all(int n,int m,int i,int j,int* adj,bool* vis){
    if( i<0 || j<0 || i>n-1 || j>m-1|| *(adj+i*n+j)==0||*(vis+i*n+j)==true)
        return;
        
    *(vis+i*n+j)=true;
    
    dfs_all(n,m,i-1,j,(int*)adj,(bool*)vis);
    dfs_all(n,m,i,j-1,(int*)adj,(bool*)vis);
    dfs_all(n,m,i,j+1,(int*)adj,(bool*)vis);
    dfs_all(n,m,i+1,j,(int*)adj,(bool*)vis);
    dfs_all(n,m,i+1,j+1,(int*)adj,(bool*)vis);
    dfs_all(n,m,i-1,j+1,(int*)adj,(bool*)vis);
    dfs_all(n,m,i+1,j-1,(int*)adj,(bool*)vis);
    dfs_all(n,m,i-1,j-1,(int*)adj,(bool*)vis);
}

void dfs_up_dow(int n,int m,int i,int j,int* adj,bool* vis){
    if( i<0 || j<0 || i>n-1 || j>m-1|| *(adj+i*n+j)==0||*(vis+i*n+j)==true)
        return;
        
    *(vis+i*n+j)=true;
    
    dfs_up_dow(n,m,i-1,j,(int*)adj,(bool*)vis);
    dfs_up_dow(n,m,i,j-1,(int*)adj,(bool*)vis);
    dfs_up_dow(n,m,i,j+1,(int*)adj,(bool*)vis);
    dfs_up_dow(n,m,i+1,j,(int*)adj,(bool*)vis); 
}

void dfs_diag(int n,int m,int i,int j,int* adj,bool* vis){
    if( i<0 || j<0 || i>n-1 || j>m-1|| *(adj+i*n+j)==0||*(vis+i*n+j)==true)
        return;
        
    *(vis+i*n+j)=true;
    
    dfs_diag(n,m,i+1,j+1,(int*)adj,(bool*)vis);
    dfs_diag(n,m,i-1,j+1,(int*)adj,(bool*)vis);
    dfs_diag(n,m,i+1,j-1,(int*)adj,(bool*)vis);
    dfs_diag(n,m,i-1,j-1,(int*)adj,(bool*)vis);
}

void dfs_ver(int n,int m,int i,int j,int* adj,bool* vis){
    if( i<0 || j<0 || i>n-1 || j>m-1|| *(adj+i*n+j)==0||*(vis+i*n+j)==true)
        return;
        
    *(vis+i*n+j)=true;
    
    dfs_ver(n,m,i-1,j,(int*)adj,(bool*)vis);
    dfs_ver(n,m,i+1,j,(int*)adj,(bool*)vis); 
}

void dfs_hor(int n,int m,int i,int j,int* adj,bool* vis){
    if( i<0 || j<0 || i>n-1 || j>m-1|| *(adj+i*n+j)==0||*(vis+i*n+j)==true)
        return;
        
    *(vis+i*n+j)=true;
    
    dfs_hor(n,m,i,j-1,(int*)adj,(bool*)vis);
    dfs_hor(n,m,i,j+1,(int*)adj,(bool*)vis); 
}

int main(){
    int n,m;
    cin>>n>>m;
    int adj[n][m];
    bool vis[n][m];
    memset(vis,false,sizeof(vis));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>adj[i][j];
        }
    }

    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]==1 && vis[i][j]==false){
                dfs_all(n,m,i,j,(int*) adj,(bool*) vis);
                count++;
            }
        }
    }
    cout<<"Horizontal_Vertical_diag: "<<count<<endl;

    memset(vis,false,sizeof(vis));
    count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]==1 && vis[i][j]==false){
                dfs_up_dow(n,m,i,j,(int*) adj,(bool*) vis);
                count++;
            }
        }
    }
    cout<<"Horizontal_Vertical: "<<count<<endl;

    memset(vis,false,sizeof(vis));
    count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]==1 && vis[i][j]==false){
                dfs_diag(n,m,i,j,(int*) adj,(bool*) vis);
                count++;
            }
        }
    }
    cout<<"Diagonal: "<<count<<endl;

    memset(vis,false,sizeof(vis));
    count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]==1 && vis[i][j]==false){
                dfs_ver(n,m,i,j,(int*) adj,(bool*) vis);
                count++;
            }
        }
    }
    cout<<"Vertical: "<<count<<endl;

    memset(vis,false,sizeof(vis));
    count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]==1 && vis[i][j]==false){
                dfs_hor(n,m,i,j,(int*) adj,(bool*) vis);
                count++;
            }
        }
    }
    cout<<"Horizontal: "<<count<<endl;

    return 0;
}

// 5 5
// 1 0 0 0 1
// 0 1 0 1 0
// 0 1 1 1 0
// 0 1 0 1 0
// 1 0 0 0 1