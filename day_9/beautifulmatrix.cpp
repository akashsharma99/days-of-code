//https://codeforces.com/contest/263/problem/A
#include<iostream>
#include<math.h>
using namespace std;
int main(){
     int row=0,col=0,a,flg=0;
     for(int i=1;i<=5 && flg==0;i++){
          for(int j=1;j<=5 && flg==0;j++){
               cin>>a;
               if(a==1){
                    row=i;
                    col=j;
                    flg=1;
               }
          }
     }
     cout<<abs(3-row)+abs(3-col);
     return 0;
}