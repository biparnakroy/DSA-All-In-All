class Solution {
public:
    int maximumSwap(int num) {
        // Convert the number to a string for easy manipulation
        string numStr = to_string(num);
        int n = numStr.size();

        // Store the last occurrence of each digit (0-9)
        vector<int> last(10, -1);

        for (int i = 0; i < n; ++i) {
            last[numStr[i] - '0'] =
                i; // Record the last occurrence of each digit
        }

        // Traverse the number from left to right
        for (int i = 0; i < n; ++i) {
            // Check for a larger digit in the future positions
            for (int d = 9; d > numStr[i] - '0'; --d) {
                if (last[d] > i) {
                    // If a larger digit exists, swap and return the result
                    swap(numStr[i], numStr[last[d]]);
                    return stoi(numStr); // Return the result as an integer
                }
            }
        }

        // No swap can improve the number, return it as is
        return num;
    }
};