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



void insert_begin(Node *&head, int x){
    Node *temp= new Node(x);
    temp->next=head;
    head = temp;
}

void insert_end(Node *&head, int x){
    Node *temp=new Node(x);
    if(head == NULL){
        head = temp;
    }
    else{
        Node *curr = head;
        while(curr->next!=NULL){
            curr=curr->next;
        }

        curr->next = temp;
    }
}


void inser_pos(Node *&head,int x, int pos){
    
}

void print_ll(Node *head){
    Node *curr = head;
    while(curr!=NULL){
        cout<<curr->val<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    Node *head1=NULL;
    Node *head2=NULL;

    while (n-->0){
       int x;
       cin>>x;
       insert_begin(head1,x);
       insert_end(head2,x);
    }

    cout<<"Insert Begin: ";
    print_ll(head1);

    cout<<"Insert End: ";
    print_ll(head2);

    return 0;
}