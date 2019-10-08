/*
https://codeforces.com/contest/791/problem/A
*/
#include<iostream>
using namespace std;
int main(){
     int lima,bear,years=0;
     cin>>lima>>bear;
     while(lima<=bear){
          lima=lima*3;
          bear=bear*2;
          years++;
     }
     cout<<years;
}