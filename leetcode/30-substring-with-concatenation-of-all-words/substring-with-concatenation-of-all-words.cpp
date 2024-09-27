class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty())
            return result;

        int wordLength = words[0].size();
        int numWords = words.size();
        int totalLength = wordLength * numWords;

        // Map to store the frequency of each word in the words list
        unordered_map<string, int> wordMap;
        for (const string& word : words) {
            wordMap[word]++;
        }

        // Check for each possible starting index offset
        for (int i = 0; i < wordLength; i++) {
            unordered_map<string, int> windowMap;
            int left = i, count = 0;

            for (int j = i; j + wordLength <= s.size(); j += wordLength) {
                string word = s.substr(j, wordLength);

                // If the word is part of the word list
                if (wordMap.find(word) != wordMap.end()) {
                    windowMap[word]++;
                    count++;

                    // Shrink the window if the word occurs more than expected
                    while (windowMap[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLength);
                        windowMap[leftWord]--;
                        left += wordLength;
                        count--;
                    }

                    // If all words are matched
                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                    // If the word is not part of the word list, reset the
                    // window
                    windowMap.clear();
                    left = j + wordLength;
                    count = 0;
                }
            }
        }

        return result;
    }
};