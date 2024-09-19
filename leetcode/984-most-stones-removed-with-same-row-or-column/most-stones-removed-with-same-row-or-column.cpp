class Solution {
public:
      void dfs(int index, vector<vector<int>>& stones, vector<int>& visited) {
        visited[index] = true;
        for (int i = 0; i < stones.size(); i++) {
            if (!visited[i] && (stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1])) {
                dfs(i, stones, visited);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int>visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,stones,visited);
            }
        }
        return n-count;
    }
};