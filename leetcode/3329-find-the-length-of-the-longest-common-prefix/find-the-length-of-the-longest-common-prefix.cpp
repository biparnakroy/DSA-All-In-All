class Solution {
public:
    vector<string> generatePrefixes(string& num) {
        vector<string> prefixes;
        string prefix = "";
        for (char ch : num) {
            prefix += ch; // Accumulate characters to form prefixes
            prefixes.push_back(prefix);
        }
        return prefixes;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefixSet; // HashSet to store prefixes from arr1
        int maxPrefixLen = 0;

        // Step 1: Generate all prefixes of each element in arr1 and store in
        // HashSet
        for (int num : arr1) {
            string strNum = to_string(num); // Convert integer to string
            vector<string> prefixes = generatePrefixes(strNum);
            for (string& prefix : prefixes) {
                prefixSet.insert(prefix); // Add all prefixes to the set
            }
        }

        // Step 2: Check each element in arr2 for matching prefixes in arr1
        for (int num : arr2) {
            string strNum = to_string(num); // Convert integer to string
            vector<string> prefixes = generatePrefixes(strNum);
            for (string& prefix : prefixes) {
                if (prefixSet.find(prefix) != prefixSet.end()) {
                    // If prefix is found in the HashSet, update the max prefix
                    // length
                    maxPrefixLen = max(maxPrefixLen, (int)prefix.length());
                }
            }
        }

        return maxPrefixLen;
    }
};