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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;
        double curr_res =0.0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            double sum =0;
            for(int i =0;i<n;i++){
                TreeNode* curr = q.front();
                sum+=curr->val;
                q.pop();
                if(curr->left!=nullptr)
                    q.push(curr->left);
                if(curr->right!=nullptr)
                    q.push(curr->right);
            }
            double avg   = sum/n;
            res.push_back(avg);
        }

        return res;

    }
};