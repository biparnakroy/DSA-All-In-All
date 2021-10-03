#include <bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    vector<Node*> children;
};


Node* make_tree(int a[],int n){
    stack<Node*> s;
    Node *root = new  Node();
    for(int i=0;i<n;i++){
        if(a[i]==-1){
            s.pop();
        }
        else{
            
        }
    }
}