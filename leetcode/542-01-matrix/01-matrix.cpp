class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> dist(rows, vector<int>(cols, 0));
        vector<vector<int>> vis(rows, vector<int>(cols, 0));

        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int dy[4] = {1, 0, -1, 0};
        int dx[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto curr = q.front();
            int curr_i = curr.first.first;
            int curr_j = curr.first.second;
            int curr_dist = curr.second;
            dist[curr_i][curr_j] = curr_dist;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int n_curr_i = curr_i + dy[i];
                int n_curr_j = curr_j + dx[i];
                int n_curr_dist = curr_dist + 1;

                if (n_curr_i >= 0 && n_curr_i < rows && n_curr_j >= 0 &&
                    n_curr_j < cols && vis[n_curr_i][n_curr_j] == 0) {
                    q.push({{n_curr_i, n_curr_j}, n_curr_dist});
                    vis[n_curr_i][n_curr_j] = 1;
                }
            }
        }

        return dist;
    }
};