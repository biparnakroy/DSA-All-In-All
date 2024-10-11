class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size(); // If array size is 2 or less, we don't need to
                                // remove any duplicates
        }

        int i = 2; // Start from index 2 because the first two elements are
                   // always valid

        // Iterate through the array starting from the 3rd element
        for (int j = 2; j < nums.size(); j++) {
            // If the current element is different from the element two
            // positions before it
            if (nums[j] != nums[i - 2]) {
                nums[i] =  nums[j]; // Move the element to the next valid position
                i++;         // Increment the pointer
            }
        }

        return i;
    }
};