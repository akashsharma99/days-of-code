#include <bits/stdc++.h>
#define fastread std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;
int main(){
     fastread;
     int T,Q,N,i,j;
     long int n;
     cin>>T;
     while(T>0){
          T--;
          cin>>N>>Q;
          long int arr[N];
          for(i=0;i<N;i++){
               cin>>n;
               if(i==0)
               arr[i]=n;
               else{
                    if(n>arr[i-1]){
                         arr[i]=n;
                    }
                    else{
                         arr[i]=arr[i-1];
                    }
               }
          }
          for(i=0;i<Q;i++){
               cin>>n;
               cout<<arr[n-1]<<'\n';
          }


     }
     return 0;
}