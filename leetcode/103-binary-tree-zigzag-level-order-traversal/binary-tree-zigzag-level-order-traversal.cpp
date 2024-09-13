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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        queue<TreeNode*>q;
        if(root==nullptr) return res;
        q.push(root);
        int flag = 0;
        while(!q.empty()){
            int level_size = q.size();
            vector<int> curr_lvl;
            for(int i =0;i<level_size;i++){
                TreeNode* curr = q.front();
                q.pop();
                curr_lvl.push_back(curr->val);
                if(curr->left!=nullptr) q.push(curr->left);
                if(curr->right!=nullptr) q.push(curr->right);
            }
            if(flag%2!=0){
                reverse(curr_lvl.begin(), curr_lvl.end());
            }
            res.push_back(curr_lvl);
            flag =!flag;
        }
        return res;
    }
};