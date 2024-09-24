class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int total_ones = 0;

        // Step 1: Count the total number of 1's in the array
        for (int num : nums) {
            if (num == 1)
                total_ones++;
        }

        // If there are no 1's, no swaps needed
        if (total_ones == 0)
            return 0;

        // Step 2: Create the "circular" array by appending nums to itself
        nums.insert(nums.end(), nums.begin(), nums.end());

        // Step 3: Sliding window approach to find the maximum number of 1's in
        // a window of size total_ones
        int max_ones_in_window = 0, current_ones = 0;

        // Initialize the window with the first total_ones elements
        for (int i = 0; i < total_ones; i++) {
            if (nums[i] == 1)
                current_ones++;
        }

        max_ones_in_window = current_ones;

        // Slide the window over the array
        for (int i = total_ones; i < nums.size(); i++) {
            // Slide the window: remove the element that is sliding out and add
            // the new element
            if (nums[i - total_ones] == 1)
                current_ones--;
            if (nums[i] == 1)
                current_ones++;

            // Update the maximum number of 1's found in any window
            max_ones_in_window = max(max_ones_in_window, current_ones);
        }

        // Step 4: Minimum swaps = total_ones - max_ones_in_window
        return total_ones - max_ones_in_window;
    }
};