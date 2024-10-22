class Solution {
public:
    // Helper function to check if a queen can be placed at board[row][col]
    bool isSafe(int row, int col, vector<string>& board, int n,
                vector<int>& cols, vector<int>& diag1, vector<int>& diag2) {
        // Check if column or diagonals are already occupied
        return !cols[col] && !diag1[row - col + n - 1] && !diag2[row + col];
    }

    // Helper function to solve the N-Queens problem using backtracking
    void solve(int row, vector<string>& board, int n, vector<int>& cols,
               vector<int>& diag1, vector<int>& diag2,
               vector<vector<string>>& result) {
        // If all queens are placed, store the board configuration
        if (row == n) {
            result.push_back(board);
            return;
        }

        // Try placing a queen in each column of the current row
        for (int col = 0; col < n; ++col) {
            if (isSafe(row, col, board, n, cols, diag1, diag2)) {
                // Place the queen
                board[row][col] = 'Q';
                cols[col] = 1; // Mark the column as occupied
                diag1[row - col + n - 1] =
                    1;                // Mark the first diagonal as occupied
                diag2[row + col] = 1; // Mark the second diagonal as occupied

                // Recurse to place the next queen
                solve(row + 1, board, n, cols, diag1, diag2, result);

                // Backtrack: remove the queen and mark the position as free
                board[row][col] = '.';
                cols[col] = 0;
                diag1[row - col + n - 1] = 0;
                diag2[row + col] = 0;
            }
        }
    }

    // Main function to solve the N-Queens problem
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>
            result; // To store all possible board configurations
        vector<string> board(n, string(n, '.')); // Create an empty chessboard

        // Vectors to mark columns and diagonals as occupied
        vector<int> cols(n, 0), diag1(2 * n - 1, 0), diag2(2 * n - 1, 0);

        // Start solving from the first row
        solve(0, board, n, cols, diag1, diag2, result);

        return result;
    }
};

