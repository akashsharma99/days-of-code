#include <bits/stdc++.h>
#define fastread std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll unsigned long long int
using namespace std;
int main(){
     fastread;
     ll T,N,i,K,j,a,sum;
     cin>>T;
     while(T>0){
          cin>>N>>K;
          sum=0;
          while(N!=0){
               N--;
               cin>>a;
               sum+=a;
          }
          cout<<sum%K<<'\n';
          T--;
     }
     return 0;
}