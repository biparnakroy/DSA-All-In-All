class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        
        for (char c : s) {
            if (c == '(') {
                low++; // treat as '('
                high++; // treat as '('
            } else if (c == ')') {
                low = max(low - 1, 0); // treat as ')', but low can't go negative
                high--; // treat as ')'
            } else if (c == '*') {
                low = max(low - 1, 0); // treat '*' as ')', but low can't go negative
                high++; // treat '*' as '('
            }
            
            if (high < 0) {
                // If high goes negative, there's an excess of closing parentheses
                return false;
            }
        }
        
        // If low is 0, we have matched all open parentheses
        return low == 0;
    }
};
