class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack; // Stack to store strings
        stack<int> numStack;    // Stack to store repeat counts
        string currString = ""; // Current decoded string
        int currNum = 0;        // Current repeat count

        for (char c : s) {
            if (isdigit(c)) {
                // If it's a digit, build the full number
                currNum = currNum * 10 + (c - '0');
            } else if (c == '[') {
                // When '[' is encountered, push the current number and string
                // onto the stack
                numStack.push(currNum);
                strStack.push(currString);

                // Reset current number and string for the next segment
                currNum = 0;
                currString = "";
            } else if (c == ']') {
                // When ']' is encountered, pop the stacks and build the
                // repeated string
                string temp = currString;
                currString = strStack.top();
                strStack.pop();
                int repeatCount = numStack.top();
                numStack.pop();

                // Append the repeated string
                while (repeatCount--) {
                    currString += temp;
                }
            } else {
                // If it's a letter, append it to the current string
                currString += c;
            }
        }

        return currString;
    }
};