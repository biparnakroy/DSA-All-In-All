class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            // Determine how many words fit into the current line
            int lineLength = words[i].size(); // length of the current word
            int j = i + 1;

            // Try to fit as many words as possible
            while (j < n &&
                   lineLength + words[j].size() + (j - i) <= maxWidth) {
                lineLength += words[j].size();
                j++;
            }

            // Number of words in the current line is j - i
            int numWordsInLine = j - i;
            int numSpaces = maxWidth - lineLength; // Total space to fill

            // Create the line
            string line;

            // If this is the last line or there's only one word in the line
            if (j == n || numWordsInLine == 1) {
                // Left-justify the words
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        line += " "; // Add space between words
                    }
                }
                // Add remaining spaces at the end
                while (line.size() < maxWidth) {
                    line += " ";
                }
            } else {
                // Full justification
                int spacesBetweenWords =
                    numSpaces / (numWordsInLine - 1); // Regular spaces
                int extraSpaces = numSpaces % (numWordsInLine -
                                               1); // Extra spaces for leftmost

                for (int k = i; k < j - 1; k++) {
                    line += words[k];
                    line += string(
                        spacesBetweenWords + (extraSpaces > 0 ? 1 : 0), ' ');
                    extraSpaces--;
                }
                // Add the last word in the line
                line += words[j - 1];
            }

            // Add the line to the result
            result.push_back(line);
            i = j; // Move to the next line
        }

        return result;
    }
};