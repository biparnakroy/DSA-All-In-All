class Solution {
public:
    int jump(vector<int>& nums) {
        int l =0, r =0, jumps=0;
        int n = nums.size();

        while(r<n-1){
            int max_jump =  0;
            for(int i =l;i<=r;i++){
                max_jump = max(max_jump, i+nums[i]);
            }
            l = r+1;
            r=max_jump;
            jumps=jumps+1;
        }
        return jumps;
    }
};