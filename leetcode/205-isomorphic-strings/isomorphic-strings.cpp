class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, char> map_s_to_t;
        unordered_map<char, char> map_t_to_s;

        for (int i = 0; i < s.size(); ++i) {
            char c1 = s[i];
            char c2 = t[i];

            // Check if there's a conflicting mapping
            if ((map_s_to_t.count(c1) && map_s_to_t[c1] != c2) ||
                (map_t_to_s.count(c2) && map_t_to_s[c2] != c1)) {
                return false;
            }

            // Map characters
            map_s_to_t[c1] = c2;
            map_t_to_s[c2] = c1;
        }

        return true;
    }
};