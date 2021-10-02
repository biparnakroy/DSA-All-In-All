//https://leetcode.com/problems/merge-intervals/


#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int,int>> intervals;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        intervals.push_back({a,b});
    }

    sort(intervals.begin(),intervals.end());
    vector<pair<int,int>> ans;
    ans.push_back(intervals[0]);
    for(int i=1;i<intervals.size();i++){
        if(intervals[i].first<=ans.back().second){
            ans.back().second=max(ans.back().second,intervals[i].second);
        }
        else{
            ans.push_back(intervals[i]);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    
    return 0;
}