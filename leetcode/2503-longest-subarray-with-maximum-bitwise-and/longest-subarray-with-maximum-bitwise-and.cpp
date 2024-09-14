class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int res =0, curr_length=0;
        for(auto x : nums){
            if(x==maxi){
                curr_length++;
                res=max(curr_length, res);
            }else{
                curr_length=0;
            }

        }
        return res;
    }
};