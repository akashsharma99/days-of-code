#include <bits/stdc++.h>
#define fastread std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;
int main(){
     fastread;
     int T,N,M,i,j;
     long int p;
     cin>>T;
     while(T>0){
          T--;
          cin>>N>>M;
          long int P[N];
          long int Q[M];
          ll S[N+M-1];
          for(i=0;i<N+M-1;i++)
          S[i]=0;
          for(i=0;i<N;i++)
          cin>>P[i];
          for(j=0;j<M;j++)
               cin>>Q[j];
          for(i=0;i<N;i++){
               for(j=0;j<M;j++){
                    S[i+j]+=P[i]*Q[j];
               }
          }
          for(i=0;i<N+M-1;i++)
          cout<<S[i]<<" ";
          cout<<'\n';
     }
     return 0;
}