/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int secondMin = -1; // To store the second minimum value

    void dfs(TreeNode* node, int rootVal) {
        if (!node)
            return;

        // If we find a value larger than the root's value, check if it's the
        // smallest "second minimum" found so far
        if (node->val > rootVal) {
            if (secondMin == -1 || node->val < secondMin) {
                secondMin = node->val;
            }
        }

        // Continue the search in both left and right subtrees
        dfs(node->left, rootVal);
        dfs(node->right, rootVal);
    }

    int findSecondMinimumValue(TreeNode* root) {
        if (!root)
            return -1;
        dfs(root, root->val);
        return secondMin;
    }
};