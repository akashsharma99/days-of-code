#include <bits/stdc++.h>
#define fastread std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;
int main(){
     fastread;
     ll T,maxv=0,profit;
     int i,j,N,S,P,V;
     cin>>T;
     while(T>0){
          T--;
          maxv=0;
          cin>>N;
          for(i=0;i<N;i++){
               cin>>S>>P>>V;
               profit=(P/(S+1))*V;
               
               if(profit>maxv){
                    maxv=profit;
               }
          }
          cout<<maxv<<'\n';
          
     }
     return 0;
}