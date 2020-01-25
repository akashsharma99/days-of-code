#include <bits/stdc++.h>
#define fastread std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;
int main(){
     fastread;
     ll T,N,alice,bob,ch,f,sol,nearest_fi;
     int i,j;
     cin>>T;
     while(T>0){
          T--;
          cin>>N>>alice>>bob>>ch;
          vector<ll> fi;
         
          for(i=0;i<N;i++){
               cin>>f;
               fi.push_back(f);
          }
          nearest_fi=fi[0];
          for(i=0;i<N;i++){
               //cout<<abs(fi[i]-bob)<<nearest_fi<<",";
               if(abs(fi[i]-bob)<=abs(bob-nearest_fi)){
                    nearest_fi=fi[i];
               }
               if(bob>alice && fi[i]<=bob && fi[i]>=alice){//friend in between bob and alice
                    nearest_fi=fi[i];
                    break;
               }
               else if(bob<alice && fi[i]>=bob && fi[i]<=alice){//friend in between bob and alice
                    nearest_fi=fi[i];
                    break;
               }
          }
          sol=abs(bob-nearest_fi)+ch+abs(nearest_fi-alice);
          cout<<sol<<'\n';
     }
     return 0;
}