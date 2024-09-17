class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCount;
        vector<string> result;
        
        stringstream ss(s1 + " " + s2); 
        string word;
        
        while (ss >> word) {
            wordCount[word]++;
        }
        
        for (auto& [word, count] : wordCount) {
            if (count == 1) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};
