#include<iostream>
#include<math.h>
using namespace std;
int main(){
     int T;
     unsigned long long int N,cpy,x,y;
     cin>>T;
     while(T!=0){
          T--;
          cin>>N;
          cpy=N;
          int count=0;
          while(N%10==0){
               count++;
               N=N/10;
          }
          x=ceil(log2(N));
          y=floor(log2(N));
          if(x==y && count>=x){
               cout<<"YES"<<"\n";
          }
          else{
               cout<<"NO"<<"\n";
          }

     }
     return 0;
}