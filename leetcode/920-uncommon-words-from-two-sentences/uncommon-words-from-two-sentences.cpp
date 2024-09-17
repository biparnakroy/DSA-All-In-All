class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCount;
        vector<string> result;
        
        stringstream ss(s1 + " " + s2); // Combine both sentences with a space between
        string word;
        
        while (ss >> word) {
            wordCount[word]++;
        }
        
        // Find all the words that appear exactly once
        for (auto& [word, count] : wordCount) {
            if (count == 1) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};
