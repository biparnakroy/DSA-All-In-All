class Solution {
public:
    int beautySum(string s) {
        int totalBeauty = 0;
        int n = s.size();

        // Iterate over every possible starting point of the substring
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0); // frequency array to store the frequency
                                     // of characters in the current substring

            // Expand the substring starting from index i
            for (int j = i; j < n; j++) {
                freq[s[j] -
                     'a']++; // update the frequency of the current character

                // Find the most frequent and least frequent character in the
                // current substring
                int maxFreq = 0;
                int minFreq = INT_MAX;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }

                // Add the beauty of the current substring to the total
                totalBeauty += (maxFreq - minFreq);
            }
        }

        return totalBeauty;
    }
};