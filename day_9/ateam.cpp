/*
https://codeforces.com/contest/231/problem/A
*/
#include<iostream>
using namespace std;
int main(){
     int n,p=0,a,b,c;
     cin>>n;
     while(n!=0){
          n--;
          cin>>a>>b>>c;
          if(a+b+c>1){
               p++;
          }
     }
     cout<<p;
     return 0;
}