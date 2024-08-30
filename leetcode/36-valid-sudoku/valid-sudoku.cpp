class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];

                // Skip empty cells
                if (num == '.')
                    continue;

                // Construct unique keys for rows, columns, and boxes
                string row_key = "row" + to_string(i) + num;
                string col_key = "col" + to_string(j) + num;
                string box_key = "box" + to_string(i / 3 * 3 + j / 3) + num;

                // Check if the key already exists in the set
                if (seen.find(row_key) != seen.end() ||
                    seen.find(col_key) != seen.end() ||
                    seen.find(box_key) != seen.end()) {
                    return false;
                }

                // Insert keys into the set
                seen.insert(row_key);
                seen.insert(col_key);
                seen.insert(box_key);
            }
        }

        return true;
    }
};