class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0, count = 0;

        // Find the maximum OR possible by combining all elements
        for (int num : nums) {
            maxOR |= num;
        }

        // Helper function for backtracking to find subsets
        dfs(nums, 0, 0, maxOR, count);

        return count;
    }

private:
    // Recursive DFS to find all subsets and their OR values
    void dfs(vector<int>& nums, int idx, int currentOR, int maxOR, int& count) {
        if (idx == nums.size()) {
            if (currentOR == maxOR) {
                count++;
            }
            return;
        }

        // Include nums[idx] in the subset
        dfs(nums, idx + 1, currentOR | nums[idx], maxOR, count);

        // Exclude nums[idx] from the subset
        dfs(nums, idx + 1, currentOR, maxOR, count);
    }
};