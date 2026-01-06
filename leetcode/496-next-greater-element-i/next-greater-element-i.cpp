class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge;   // value → next greater
        int n = nums2.size();
        stack<int> st;
        for(int i =n-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(st.empty()) nge[nums2[i]]=-1;
            else nge[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        vector<int>res;
        for(auto x:nums1){
            res.push_back(nge[x]);
        }
        return res;
    }
};