#include <bits/stdc++.h>
#define fastread std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;
int main(){
     fastread;
     int T,N,x,i,j;
     cin>>T;
     vector<int> sequence;
     unordered_map<int,int> mp;
     int n=130,num=0;
     //cout<<num<<",";
     sequence.push_back(-1);
     sequence.push_back(num);
     for(int i=1;i<n;i++){
          if(mp.find(num)==mp.end()){//not present earlier in sequence
               mp[num]=i;
               num=0;
               
          }
          else{
               int newnum=i-mp[num];
               mp[num]=i;
               num=newnum;
               //mp[num]=i+1;
          }
          sequence.push_back(num);
          //cout<<num<<",";
     }
     while(T>0){
          T--;
          cin>>N;
          int count=0;
          x=sequence[N];
          for(i=1;i<=N;i++){
               if(x==sequence[i])
               count++;
          }
          cout<<count<<'\n';
     }
     return 0;
}