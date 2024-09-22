/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void help(TreeNode*root, int targetSum,int &count){
        if(root==nullptr){
            return;
        }
        targetSum -= root->val;
        if(root->left==nullptr && root->right==nullptr && targetSum==0){
            count++;
        }
        help(root->left,targetSum,count);
        help(root->right,targetSum,count);

    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int count =0;
        help(root, targetSum, count);
        return (count>0)?true:false;
    }
};