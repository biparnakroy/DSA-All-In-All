#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void pre_order(Node *root)
{
    if (!root)
        return;
    cout << (root->data) << " ";
    pre_order(root->left);
    pre_order(root->right);
}

int find_index_bracket(string str, int si, int ei)
{

    if (si > ei)
        return -1;
    stack<char> s;
    for (int i = si; i <= ei; i++)
    {
        if (str[i] == '(')
            s.push(str[i]);
        else if (str[i] == ')')
        {
            if (s.top() == '(')
            {
                s.pop();
                if (s.empty())
                    return i;
            }
        }
    }
    return -1;
}

Node *string_to_tree(string str, int si, int ei)
{
    if (si > ei)
        return NULL;
    Node *root = new Node(str[si] - '0');
    int index = -1;
    if (si + 1 <= ei && str[si + 1] == '(')
        index = find_index_bracket(str, si + 1, ei);
    if (index != -1)
    {
        root->left = string_to_tree(str, si + 2, index - 1);
        root->right = string_to_tree(str, index + 2, ei - 1);
    }
    return root;
}

int main()
{
    string s;
    cin >> s;
    Node *root = NULL;
    root = string_to_tree(s, 0, s.length() - 1);
    pre_order(root);
    return 0;
}