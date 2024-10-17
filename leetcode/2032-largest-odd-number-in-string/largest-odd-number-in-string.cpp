class Solution {
public:
    string largestOddNumber(string num) {
        // Traverse the string from right to left
        for (int i = num.size() - 1; i >= 0; --i) {
            // Check if the current digit is odd
            if ((num[i] - '0') % 2 == 1) {
                // Return the substring from the start to the current index
                // (inclusive)
                return num.substr(0, i + 1);
            }
        }
        // If no odd digit is found, return an empty string
        return "";
    }
};