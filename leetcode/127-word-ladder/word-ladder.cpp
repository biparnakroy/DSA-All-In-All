class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end())
            return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> visited;
        visited.insert(beginWord);

        while (!q.empty()) {
            auto [currentWord, level] = q.front();
            q.pop();

            for (int i = 0; i < currentWord.size(); i++) {
                string temp = currentWord;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;
                    if (temp == endWord) {
                        return level + 1;
                    }
                    if (wordSet.find(temp) != wordSet.end() &&
                        visited.find(temp) == visited.end()) {
                        q.push({temp, level + 1});
                        visited.insert(temp);
                    }
                }
            }
        }

        return 0;
    }
};
