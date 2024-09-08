class Solution {
public:
    bool bfs(vector<vector<int>>&graph, vector<int>&color,int start){
        queue<int>q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(auto x:graph[curr]){
                if(color[x]==-1){
                    color[x]=!color[curr];
                    q.push(x);
                }else if(color[x]==color[curr]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(bfs(graph,color,i)==false){
                    return false;
                }
            }
        }
        return true;
    }
};