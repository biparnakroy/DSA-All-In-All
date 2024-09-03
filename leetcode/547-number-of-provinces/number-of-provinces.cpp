class Solution {
public:
        void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
        // Mark the current city as visited
        visited[i] = true;

        // Visit all the cities that are directly connected and not visited
        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[i][j] == 1 && !visited[j]) {
                dfs(isConnected, visited, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int numProvinces = 0;

        // Iterate over each city
        for (int i = 0; i < n; i++) {
            // If a city is not visited, it's a new province
            if (!visited[i]) {
                numProvinces++;
                dfs(isConnected, visited, i);
            }
        }

        return numProvinces;
    }

};