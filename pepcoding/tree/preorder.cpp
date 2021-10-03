#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};

/*
        1
       / \
      2   3
     / \   \ 
    4   5   6

    pre:  1 2 4 5 3 6
    in:   4 2 5 1 3 6
    post: 4 5 2 6 3 1

*/

void inOrderIt(Node *root){
    stack<Node*> s;
    Node *current=root;
    while(current!=NULL || s.empty()==false){
        while (current!=NULL)
        {
            s.push(current);
            current=current->left;
        }
        current=s.top();
        s.pop();
        cout<<current->data<<" ";
        current=current->right;
    }
}
void preOrderIt(Node *root){
    stack<Node*> s;
    s.push(root);
    while(s.empty()==false){
         Node *current = s.top();
         s.pop();
         cout<<current->data<<" ";
        
        if(current->right!=NULL)
            s.push(current->right);

        if(current->left!=NULL)
            s.push(current->left);
    }
}

void postOrderIt(Node *root){
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);
    Node *current = NULL;
    while (s1.empty()==false)
    {
        current = s1.top();
        s1.pop();
        s2.push(current);
        if(current->left !=NULL)
            s1.push(current->left);
        if(current->right !=NULL)
            s1.push(current->right);
    }
    while(s2.empty()==false){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}

int main(){
    Node *root= new Node(1);
    root->left= new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->right=new Node(6);

    inOrderIt(root);
    cout<<"\n";
    preOrderIt(root);
    cout<<"\n";
    postOrderIt(root);
    cout<<"\n";

    return 0;
}