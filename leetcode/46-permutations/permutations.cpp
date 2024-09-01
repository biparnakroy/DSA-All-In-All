class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, int start) {
        // If we've reached the end of the array, we've found a valid
        // permutation
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }

        // Explore permutations by swapping each element with the current start
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start],
                 nums[i]); // Swap the current element with the start
            backtrack(nums, res,
                      start + 1); // Recur to generate permutations for the rest
            swap(nums[start],
                 nums[i]); // Backtrack to restore the original array
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums, res, 0);
        return res;
    }
};