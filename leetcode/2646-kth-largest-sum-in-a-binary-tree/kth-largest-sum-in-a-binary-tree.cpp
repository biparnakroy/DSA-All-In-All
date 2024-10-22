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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root)
            return -1;

        // Use a min-heap to store the largest k sums
        priority_queue<long long, vector<long long>, greater<long long>>
            minHeap;
        queue<TreeNode*> q;
        q.push(root);

        // Perform level order traversal
        while (!q.empty()) {
            int levelSize = q.size();
            long long levelSum = 0;

            // Calculate the sum of the current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;

                // Add child nodes to the queue
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // Maintain a heap of the k largest sums
            if (minHeap.size() < k) {
                minHeap.push(levelSum);
            } else if (levelSum > minHeap.top()) {
                minHeap.pop();
                minHeap.push(levelSum);
            }
        }

        // If we have fewer than k levels, return -1
        return minHeap.size() == k ? minHeap.top() : -1;
    }
};