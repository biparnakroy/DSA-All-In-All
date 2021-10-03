#include <bits/stdc++.h>
using namespace std;

struct ticket{
    string src;
    string dst;
};

ticket book_ticket(string src, string dst){
    ticket t;
    t.src=src;
    t.dst=dst;
    return t;
}


int main(){
    
    int n;
    cin>>n;
    
    vector<ticket> iten;
    map<string, int> mp;
    
    for(int i=0;i<n;i++){
        string s,d;
        cin>>s>>d;
        mp[s]++;
        mp[d]--;
        iten.push_back(book_ticket(s,d));
    }
    string src,dst;
    for(auto x: mp){
        if(x.second==-1)
            dst=x.first;
        else if(x.second==1)
            src=x.first;
    }
    
    while(src!=dst){
        cout<<src<<" -> ";
        for(int i=0;i<iten.size();i++){
            if(iten[i].src==src){
                src=iten[i].dst;
                break;
            }
        }
    }   
    cout<<dst<<"."<<endl;

    return 0;
}

/*
    Chennai : chennai->bangalore,  
    Bangalore : bangalore->"",
    Bombay : bombay->delhi,
    Delhi : delhi->"",
    Goa : goa->chennai,

Chennai->Banglore  che : 0
Bombay->Delhi      Bo : 1
Goa->Chennai       go : 1
Delhi->Goa   


ch: 0
ba: -1
bo: 1
de: 0
go: 0



*/