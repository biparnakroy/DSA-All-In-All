class Solution {
public:
    int findNthDigit(int n) {
        long long digitLength = 1; // Start with 1-digit numbers
        long long count = 9;       // There are 9 one-digit numbers
        long long start = 1;       // Starting number in each group

        // Step 1: Identify the group (1-digit, 2-digit, 3-digit, ...)
        while (n > digitLength * count) {
            n -= digitLength * count;
            digitLength++;
            count *= 10;
            start *= 10;
        }

        // Step 2: Find the exact number
        start += (n - 1) / digitLength;

        // Step 3: Find the digit in the number
        string s = to_string(start);
        return s[(n - 1) % digitLength] - '0';
    }
};