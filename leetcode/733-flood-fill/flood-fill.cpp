class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j,int c_color, int color){
        if(i<0||j<0||i>=image.size()||j>=image[0].size()||image[i][j]==color||image[i][j]!=c_color) return;
        image[i][j]=color;
        dfs(image,i+1,j,c_color,color);
        dfs(image,i-1,j,c_color,color);
        dfs(image,i,j+1,c_color,color);
        dfs(image,i,j-1,c_color,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};