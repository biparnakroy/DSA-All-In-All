class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> vowelToBit = {
            {'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};

        unordered_map<int, int> bitmaskIndex;
        bitmaskIndex[0] = -1;

        int bitmask = 0;
        int maxLength = 0;

        for (int i = 0; i < s.size(); i++) {
            if (vowelToBit.count(s[i])) {
                bitmask ^= (1 << vowelToBit[s[i]]);
            }

            if (bitmaskIndex.count(bitmask)) {
                maxLength = max(maxLength, i - bitmaskIndex[bitmask]);
            } else {
                bitmaskIndex[bitmask] = i;
            }
        }

        return maxLength;
    }
};
