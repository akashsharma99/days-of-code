/*
https://codeforces.com/contest/734/problem/A
*/
#include<iostream>
using namespace std;
int main(){
     int n;
     cin>>n;
     char ch;
     int ant=0,dan=0;
     for(int i=0;i<n;i++){
          cin>>ch;
          if(ch=='A')
               ant++;
          else
               dan++;
     }
     if(ant==dan)
          cout<<"Friendship";
     else if(ant>dan)
          cout<<"Anton";
     else
          cout<<"Danik";
     return 0;
}