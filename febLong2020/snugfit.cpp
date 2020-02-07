#include <bits/stdc++.h>
#define fastread std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;
int main(){
     fastread;
     int T,N,i,j;
     cin>>T;
     int a;
     while(T>0){
          cin>>N;
          ll sum=0;
          vector<int> arr1;
          vector<int> arr2;
          for(i=0;i<N;i++){
               cin>>a;
               arr1.push_back(a);
          }
          for(i=0;i<N;i++){
               cin>>a;
               arr2.push_back(a);
          }
         
          sort(arr1.begin(),arr1.end());
          sort(arr2.begin(),arr2.end());

          for(i=0;i<N;i++){
               
               sum+=(arr1[i]<=arr2[i])?arr1[i]:arr2[i];
          }
          cout<<sum<<'\n';
          T--;
     }
     return 0;
}