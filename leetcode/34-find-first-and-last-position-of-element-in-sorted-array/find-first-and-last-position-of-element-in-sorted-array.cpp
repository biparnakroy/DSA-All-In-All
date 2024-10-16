class Solution {
public:
    // Function to find the first occurrence of the target
    int findFirst(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int first = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                first = mid;    // Found target, store the index
                high = mid - 1; // Keep searching towards the left for the first
                                // occurrence
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return first;
    }

    // Function to find the last occurrence of the target
    int findLast(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int last = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                last = mid;    // Found target, store the index
                low = mid + 1; // Keep searching towards the right for the last
                               // occurrence
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return last;
    }

     vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        if (first == -1) {
            return {-1, -1};  // If target is not found, return [-1, -1]
        }
        
        int last = findLast(nums, target);
        return {first, last};  // Return the first and last occurrence indices
    }
   
};