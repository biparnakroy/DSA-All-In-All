/*
https://www.pepcoding.com/resources/online-java-foundation/hashmap-and-heap/lcqs-official/ojquestion

solution : https://www.youtube.com/watch?v=YWXbu5uyGXs&t=487s
Topic : Hashing
Two : variants one will ask just to find the length other will ask you to print the sequence
Note : here in this question the order of subsequence is not maintained
*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    unordered_map<int,bool> m;

    //intially declearing all the elements as starting point of sequence
    for(int i=0;i<n;i++) m[a[i]]=true;

    // find the starting points of the sequence
    for(int i=0;i<n;i++){
        if(m.find(a[i]-1) != m.end())
            m[a[i]]=false;
    }

    // for(auto x:m)
    //     cout<<x.first<<" "<<x.second<<endl;

    int max_start_point = 0;
    int max_length=0;

    for(auto x:a){
       if(m[x]){
           int temp_length=1;
           int temp_start_point=x;
           while(m.find(temp_start_point + temp_length)!=m.end()){
               temp_length++;
           }

           if(temp_length>max_length){
               max_length=temp_length;
               max_start_point=temp_start_point;
           }
       }
    }

    cout<<"length of sequence: "<<max_length<<endl;
    cout<<"The sequence is : ";
    for(int i=0;i<max_length;i++){
        cout<<max_start_point+i<<" ";
    }
    cout<<endl;

    return 0;
}