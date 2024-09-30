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
public:
    int maxPathSum(TreeNode* root) {
        int maxSum =
            INT_MIN; // Initialize the global maximum to a very small value
        maxGain(
            root,
            maxSum); // Post-order traversal to calculate the maximum path sum
        return maxSum;
    }

private:
    // Helper function to calculate max gain from a given node
    int maxGain(TreeNode* node, int& maxSum) {
        if (node == nullptr)
            return 0; // Base case: null nodes contribute 0 to the path

        // Recursively calculate the max gain from the left and right subtrees
        int leftGain = max(maxGain(node->left, maxSum),
                           0); // If left gain is negative, discard it (use 0)
        int rightGain = max(maxGain(node->right, maxSum),
                            0); // If right gain is negative, discard it (use 0)

        // Calculate the price of the new path including the current node
        int currentPathSum = node->val + leftGain + rightGain;

        // Update the global maximum sum if the current path is better
        maxSum = max(maxSum, currentPathSum);

        // Return the max gain if we continue the path through this node
        return node->val + max(leftGain, rightGain);
    }
};