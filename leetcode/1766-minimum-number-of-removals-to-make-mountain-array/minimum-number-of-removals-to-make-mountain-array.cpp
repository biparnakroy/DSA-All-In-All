class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1); // Longest Increasing Subsequence from the left
        vector<int> lds(n, 1); // Longest Decreasing Subsequence from the right

        // Calculate LIS for each element
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }

        // Calculate LDS for each element
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j]) {
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }

        // Find the maximum mountain length
        int maxMountainLength = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (lis[i] > 1 &&
                lds[i] > 1) { // Only consider peaks with valid LIS and LDS
                maxMountainLength = max(maxMountainLength, lis[i] + lds[i] - 1);
            }
        }

        // Calculate the minimum number of removals
        return n - maxMountainLength;
    }
};