/*Problem 1 of Mustafa's Coding Sheet
http://codeforces.com/contest/677/problem/A
Vanya and friends
*/
#include<iostream>
using namespace std;
int main(){
     int n,h,height,road=0;
     cin>>n>>h;
     for(int i=0;i<n;i++){
          cin>>height;
          if(height>h){
               road+=2;
          }
          else{
               road+=1;
          }
     }
     cout<<road;
     return 0;
}