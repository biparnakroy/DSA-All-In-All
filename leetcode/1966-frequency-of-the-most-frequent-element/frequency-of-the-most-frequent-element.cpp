class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int n = nums.size();
        long long max_frequency = 0;
        long long sum = 0;
        sort(nums.begin(), nums.end());
        for(int right = 0; right<n; right++){
            sum+=nums[right];
            while((long long) nums[right]*(right-left+1)-sum > k){
                sum-=nums[left];
                left++;
            }
            max_frequency = max(max_frequency,(long long)(right-left+1));
        }
        return max_frequency;
    }
};