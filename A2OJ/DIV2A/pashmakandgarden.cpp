#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define MAXN 100000

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2;
    int x=x1-x2,y=y1-y2;
    if(x!=0 && y!=0){
        x3=x1;
        y3=y2;
        x4=x2;
        y4=y1;
    }
    else if(x!=0){
        x3=x1;
        y3=y1+abs(x);
        x4=x2;
        y4=y2+abs(x);
    }
    else{
        x3=x1+abs(y);
        y3=y1;
        x4=x2+abs(y);
        y4=y2;
    }
    if(x!=0&&y!=0&&abs(x)!=abs(y))
        cout<<-1;
    else
        cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4;
    return 0;
}