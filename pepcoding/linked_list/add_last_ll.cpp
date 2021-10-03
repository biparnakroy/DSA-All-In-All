#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next;
    Node(int x){
        val=x;
        next=NULL;
    }
};

void insert_last(Node *&head, int x){
    Node *temp = new Node(x);
    Node *curr = head;
    if(curr==NULL){
        head->val=x;
        return;
    }
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
}

int main(){
    Node *head=NULL;
    // Node *head= new Node(1);
    // head->next = new Node(2);
    // head->next->next = new Node(3);

    insert_last(head,4);

    Node *curr = head;
    while(curr!=NULL){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
    cout<<endl;
    return 0;
}