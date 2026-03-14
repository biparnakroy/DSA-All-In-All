class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reached = 0;
        int n = nums.size();
        for(int i =0;i<n;i++){
        if(i>max_reached) return false;
        max_reached = max(max_reached, i + nums[i]);
        }
        return true;
    }
};