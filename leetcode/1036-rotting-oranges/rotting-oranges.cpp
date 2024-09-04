class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int freshOranges = 0;
        
        // Initialize the queue with all the rotten oranges
        // and count the number of fresh oranges
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        if (freshOranges == 0) return 0; // No fresh oranges to rot

        int minutes = 0;
        vector<int> dirX = {-1, 1, 0, 0};
        vector<int> dirY = {0, 0, -1, 1};

        // Perform BFS
        while (!q.empty()) {
            int qSize = q.size();
            bool rotted = false;

            for (int i = 0; i < qSize; ++i) {
                auto [x, y] = q.front();
                q.pop();

                // Explore the 4 possible directions
                for (int d = 0; d < 4; ++d) {
                    int nx = x + dirX[d];
                    int ny = y + dirY[d];

                    // Check if the new position is within bounds and has a fresh orange
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2; // Make the orange rotten
                        q.push({nx, ny});
                        freshOranges--;
                        rotted = true;
                    }
                }
            }

            if (rotted) minutes++;
        }

        // If there are still fresh oranges left, return -1
        return (freshOranges == 0) ? minutes : -1;
    }
};