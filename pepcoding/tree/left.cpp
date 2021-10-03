#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int n)
    {
        val = n;
        left = NULL;
        right = NULL;
    }
};

void left_view(Node *root)
{

    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (q.empty() == false)
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == 0)
                cout << curr->val << " ";
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
}


int maxlevel=0;
void left_view_rec(Node *root, int level){
    if(root==NULL)
        return;
    if(maxlevel<level){
        cout<<root->val<<" ";
        maxlevel=level;
    }
    if(root->left!=NULL)
        left_view_rec(root->left,level+1);
     if(root->right!=NULL)
        left_view_rec(root->right,level+1);
}

int maxlevelr=0;
void right_view_rec(Node *root, int level){
    if(root==NULL)
        return;
    if(maxlevelr<level){
        cout<<root->val<<" ";
        maxlevelr=level;
    }
    right_view_rec(root->right,level+1);
    right_view_rec(root->left,level+1);
}

void top_view(Node *root)
{
    if (root == NULL)
        return;

    map<int, Node*> m;
    queue<pair<Node*,int>> q;
    q.push({root, 0});
    while (q.empty() == false)
    {
        Node *curr = q.front().first;
        int h = q.front().second;
        q.pop();
        if (!m[h])
            m[h] = curr;
        if (curr->left != NULL)
            q.push({curr->left,h-1});
        if (curr->right != NULL)
            q.push({curr->right,h+1});
    }

    for (auto x : m)
    {
        cout<<x.second->val<< " ";
    }
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    left_view(root);
    cout << endl;
    top_view(root);
    cout<<endl;
    left_view_rec(root,1);
    cout<<endl;

    right_view_rec(root,1);
    cout<<endl;

    return 0;
}
