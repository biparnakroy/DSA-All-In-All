class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end());
        int min_idx = n; // Start with a large number
        int max_width = 0;
        for (auto& p : arr) {
            int value = p.first;
            int idx = p.second;

            // Calculate the ramp width as the difference between current index
            // and min_idx
            max_width = max(max_width, idx - min_idx);

            // Update min_idx with the smallest index encountered so far
            min_idx = min(min_idx, idx);
        }
        return max_width;
    }
};