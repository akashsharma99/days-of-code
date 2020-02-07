#include <bits/stdc++.h>
#define fastread std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll unsigned long long int
using namespace std;
int main(){
     fastread;
     int T,N,i,K,j,a,sum;
     cin>>T;
     char ch;
     int slot=0,mov=0;
     int earning=0,P;
     
     while(T>0){
          int M[][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
          int mvisit[]={0,0,0,0};
          int tvisit[]={0,0,0,0};
          int sale=0;
          cin>>N;
          P=100;
          for(i=0;i<N;i++){
               cin>>ch>>slot;
               mov=((int)ch)-65;
               switch(slot){
                    case 12:slot=0;break;
                    case 3:slot=1;break;
                    case 6:slot=2;break;
                    case 9:slot=3;break;
               }
               M[mov][slot]+=1;
          }
          for(i=0;i<4;i++){
               int maxR=0,mv=-1,ts=-1;
               for(mov=0;mov<4;mov++){
                    if(mvisit[mov]==0){
                         for(slot=0;slot<4;slot++){
                              if(M[mov][slot]>maxR && tvisit[slot]==0){
                                   maxR=M[mov][slot];
                                   mv=mov;
                                   ts=slot;
                              }
                         }
                    }
               }
               sale=sale+(maxR*P);
               P-=25;
               if(mv!=-1)mvisit[mv]=1;
               if(ts!=-1)tvisit[ts]=1;
          }
          for(i=0;i<4;i++){
               if(tvisit[i]==0){
                    sale=sale-100;
               }
          }
          cout<<sale<<'\n';
          earning+=sale;
          T--;
     }
     cout<<earning<<'\n';
     return 0;
}