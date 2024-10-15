class Solution {
public:
    long long minimumSteps(string s) {
        long long  zeroCount = 0; // Count of '0's encountered
        long long  swapCount = 0; // Count of swaps needed

        reverse(s.begin(), s.end());

        // Traverse the string
        for (char c : s) {
            if (c == '0') {
                zeroCount++; // Increment zero count when we encounter '0'
            } else if (c == '1') {
                swapCount += zeroCount; // Add the number of '0's we've seen
                                        // before this '1'
            }
        }

        return swapCount;
    }
};