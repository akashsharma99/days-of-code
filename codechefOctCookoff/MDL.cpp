#include<iostream>
using namespace std;
int main(){
     int T,N;
     cin>>T;
     while(T!=0){
          T--;
          cin>>N;
          int min=110,max=0,pmin=0,pmax=0;
          for(int i=0;i<N;i++){
               int x;
               cin>>x;
               if(x<=min){
                    pmin=i;
                    min=x;
               }
               if(x>=max){
                    pmax=i;
                    max=x;
               }
          }
          if(pmin<=pmax){
               cout<<min<<" "<<max<<"\n";
          }
          else
               cout<<max<<" "<<min<<"\n";
     }
     return 0;
}