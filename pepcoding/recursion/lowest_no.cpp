// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
	public:
   	string minimum_Number(string s){
   	   sort(s.begin(),s.end());
   	   int i=0;
   	   while(s[i]=='0')
   	        i++;

		if(i!=s.length())
	   		swap(s[i],s[0]);
	  
   	   return s;
   	}    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		string ans = ob.minimum_Number(s);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends