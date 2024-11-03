class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }

        // Check if goal is a substring of s+s
        string doubled_s = s + s;
        return doubled_s.find(goal) != string::npos;
    }
};