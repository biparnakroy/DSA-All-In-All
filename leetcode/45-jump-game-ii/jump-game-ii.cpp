class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0;
        int n = nums.size();
        int j = 0;
        while (r < n - 1) {
            int new_r = r;
            for (int i = l; i <= r; i++) {
                new_r = max(new_r, i + nums[i]);
            }
            l = r + 1;
            r = new_r;
            j++;
        }
        return j;
    }
};
