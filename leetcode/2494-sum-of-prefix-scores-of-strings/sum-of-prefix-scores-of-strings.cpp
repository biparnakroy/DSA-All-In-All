class TrieNode {
public:
    TrieNode* children[26]; // For 26 lowercase English letters
    int count;              // To count how many times this prefix has been seen

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        count = 0;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    // Insert a word into the Trie and update the count for each prefix
    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
            node->count++; // Increment the prefix count
        }
    }

    // Query the sum of prefix scores for a word
    int getPrefixScore(const string& word) {
        TrieNode* node = root;
        int score = 0;
        for (char ch : word) {
            int index = ch - 'a';
            node = node->children[index];
            score += node->count; // Add the count of this prefix to the score
        }
        return score;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;

        // Insert all the words into the Trie
        for (const string& word : words) {
            trie.insert(word);
        }

        vector<int> result;

        // For each word, calculate the prefix score using the Trie
        for (const string& word : words) {
            result.push_back(trie.getPrefixScore(word));
        }

        return result;
    }
};