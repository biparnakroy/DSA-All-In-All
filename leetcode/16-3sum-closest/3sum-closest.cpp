class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
                // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        int closestSum = nums[0] + nums[1] + nums[2]; // Initialize the closest sum

        // Step 2: Iterate through the array
        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1;
            int right = nums.size() - 1;

            // Step 3: Use two-pointer technique to find the best pair
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                // If the current sum is exactly the target, return it
                if (currentSum == target) {
                    return currentSum;
                }

                // Update the closest sum if the current one is closer
                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }

                // Move the pointers based on the comparison with the target
                if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        // Return the closest sum
        return closestSum;
    }
};