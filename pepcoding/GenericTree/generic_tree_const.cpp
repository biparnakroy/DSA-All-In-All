#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    vector <Node*> children;
};

/*
                         __ 10__________
                       /    \           \
                      20     30______   40
                    /   \    |   |   |   \
                   50    60  70  80  90   100
                                / \
                             110   120
*/

void print_tree(Node *root){
    string s = to_string(root->data) + "-> ";
    for( Node *child : root->children){
        s+=to_string(child->data) + ", ";
    }
    s+=".";
    cout<<s<<endl;
    for(Node *child1 : root->children){
        print_tree(child1);
    }
}

int main(){
    int arr[24] = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    int n= sizeof(arr)/sizeof(arr[0]);
    Node *root =new Node();
    stack<Node*> s;

    for(int i=0;i<n;i++){
        if(arr[i]==-1){
            s.pop();
        }
        else{
           Node *temp= new Node();
           temp->data = arr[i];
           if(s.empty()!=true){
                s.top()->children.push_back(temp);
           }
           else{
               root=temp;
           }
           s.push(temp);
        }
    }

    print_tree(root);

    return 0;
}