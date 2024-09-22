class Solution {
public:
    vector<int> computeLPS(string& s) {
        int n = s.size();
        vector<int> lps(n, 0); // LPS array
        int len = 0;           // Length of the previous longest prefix suffix
        int i = 1;

        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    // Function to find the shortest palindrome
    string shortestPalindrome(string s) {
        // Reverse the original string
        string rev_s = string(s.rbegin(), s.rend());

        // Create the new string 'temp' = s + '#' + reverse(s)
        string temp = s + "#" + rev_s;

        // Compute the LPS array for the concatenated string
        vector<int> lps = computeLPS(temp);

        // The length of the longest palindromic prefix is in the last entry of
        // the LPS array
        int pal_len = lps.back();

        // Add the necessary characters from the reverse of s (excluding the
        // palindromic prefix)
        string to_add = rev_s.substr(0, s.size() - pal_len);

        // Return the shortest palindrome
        return to_add + s;
    }
};