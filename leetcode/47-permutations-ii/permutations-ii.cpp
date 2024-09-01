class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& res,
                   vector<int>& perm, vector<bool>& used) {
        // If the permutation is complete, add it to the result
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // Skip used elements
            if (used[i])
                continue;

            // Skip duplicates (only the first occurrence should be used in a
            // given depth)
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            // Mark this element as used
            used[i] = true;
            perm.push_back(nums[i]);

            // Recur to generate permutations with the current element included
            backtrack(nums, res, perm, used);

            // Backtrack by unmarking the element and removing it from the
            // current permutation
            used[i] = false;
            perm.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end()); // Sort to handle duplicates

        backtrack(nums, res, perm, used);
        return res;
    }
};