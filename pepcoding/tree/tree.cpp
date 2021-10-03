#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int x){
        data =x;
        left=NULL;
        right=NULL;
    }
};

Node* reverse(Node *root){
    if(root->left==NULL && root->right==NULL)
        return root;
    Node *temp=root->left;
    root->left=root->right;
    root->right=temp;
    reverse(root->left);
    reverse(root->right);
}

void  printTree(Node *root){
    if(root==NULL)
        return;
        
    printTree(root->left);
    printTree(root->right);
    cout<<root->data<<" ";
}

void printTreeIterInorder(Node *root){
    Node *current = root;
    stack<Node*> s;
    while(current!=NULL || s.empty()==false){
        while(current!=NULL){
            s.push(current);
            current=current->left;
        }
        current=s.top();
        s.pop();
        cout<<current->data<<" ";
        current=current->right;
    }
    
}



int main() {
	//code
	
	Node *root = new Node(5);
	root->left=new Node(3);
	root->right=new Node(6);
	root->left->left=new Node(2);
	root->left->right=new Node(4);
	
	printTree(root);
	cout<<"\n";
	reverse(root);
	
	printTree(root);
	
	return 0;
}
