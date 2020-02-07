/*input:
3
2 10
1 5
2 4
1 5
3 25
3 5 10
output:
NO
YES 0 1
YES 2 0 2
*/
#include <bits/stdc++.h>
#define fastread std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;
int main(){
     fastread;
     int P,T,N,op,t;
     int flag;
     cin>>T;
     while(T>0){
          cin>>N>>P;
          ll a;
          vector<int> D(N,0);
          vector<int> C(N,0);
          for(int i=0;i<N;i++){
               cin>>D[i];
          }
          op=P;
          flag=0;
          t=0;
         
          for(int i=N-1;i>=0;i--){
               
               if(P % D[i] == 0){
                    C[i]=(P / D[i]) - 1;
                    P = P - (C[i] * D[i]);
                    t=t+ (C[i] * D[i]);
               }
               else{
                    C[i]=(P / D[i]) + 1;
                    P = P - (C[i] * D[i]);
                    t=t+ (C[i] * D[i]);
               }
               if(t>op){
                    cout<<"YES";
                    flag=1;
                    for(int j=0;j<N;j++){
                         cout<<" "<<C[j];
                    }
                    cout<<'\n';
                    break;
               }
          }
          if(flag==0){
               cout<<"NO\n";
          }
          T--;
     }
     return 0;
}