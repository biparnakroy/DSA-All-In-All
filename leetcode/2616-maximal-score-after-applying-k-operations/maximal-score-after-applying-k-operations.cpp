class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // Use a max heap to keep track of the largest elements
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        long long totalScore = 0;

        while (k-- > 0) {
            // Extract the largest element
            int largest = maxHeap.top();
            maxHeap.pop();

            // Add the largest element to the total score
            totalScore += largest;

            // Calculate the ceil value of the largest element divided by 3
            int newValue = ceil(largest / 3.0);

            // Insert the new value back into the heap
            maxHeap.push(newValue);
        }
        return totalScore;
    }
};