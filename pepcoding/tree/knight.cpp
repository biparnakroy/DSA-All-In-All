#include <bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int steps=0;
	    int dir_x[]={-2,-1,1,2,2,1,-1,-2};
	    int dir_y[]={1,2,2,1,-1,-2,-2,-1};
	    pair<int,int> s={KnightPos[0]-1,N-KnightPos[1]};
	    pair<int,int> t={TargetPos[0]-1,N-TargetPos[1]};
        cout<< s.first <<" "<< s.second <<endl;
	    bool visited[N][N];
	    memset(visited,false, sizeof(visited));
	    queue<pair<int,int>>q;
    
	    q.push(s);
	    visited[s.second][s.first]=true;
	    while(q.empty()==false){
	        //cout<<"yes"<<endl;
	        pair<int,int> current = q.front();
            //cout<<current.first<<" "<<current.second<<endl;
              
	        if(current==t)
	            break;
	        q.pop();
	        steps++;
	        for(int i=0;i<8;i++){
	            int n_x=current.first+dir_x[i];
	            int n_y=current.second+dir_y[i];
	            if(n_x>=0 && n_y>=0 && n_x<N && n_y<N && visited[n_x][n_y]==false){
	                visited[n_y][n_x]=true;
	                q.push({n_x,n_y});
	            }
	        }
	    }
	 
	    return steps;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Cod