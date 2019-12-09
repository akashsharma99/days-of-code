#include <bits/stdc++.h>
#define fastread std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ull unsigned long long int
using namespace std;
int main(){
     fastread;
     int T,N,M,K,i,j,k;
     ull a,b,x,y;
     cin>>T;
     while(T>0){
          T--;
          cin>>x>>y;
          cin>>N>>M>>K;
          pair<ull,ull> reds[N];
          pair<ull,ull> greens[M];
          pair<ull,ull> blues[K];
          long double d,d1=0,d2=0,d3=0,distMin=FLT_MAX;
          for(i=0;i<N;i++){
               cin>>a>>b;
               reds[i]=(make_pair(a,b));
          }
          for(i=0;i<M;i++){
               cin>>a>>b;
               greens[i]=(make_pair(a,b));
          }
          for(i=0;i<K;i++){
               cin>>a>>b;
               blues[i]=(make_pair(a,b));
          }
          for(i=0;i<N;i++){
               d1=sqrtl((x-reds[i].first)*(x-reds[i].first)+(y-reds[i].second)*(y-reds[i].second));

               for(j=0;d1<distMin && j<M;j++){
                    d2=sqrtl((reds[i].first-greens[j].first)*(reds[i].first-greens[j].first)+(reds[i].second-greens[j].second)*(reds[i].second-greens[j].second));
                    for(k=0;(d1+d2<distMin) && k<K;k++){
                         d3=sqrtl((blues[k].first-greens[j].first)*(blues[k].first-greens[j].first)+(blues[k].second-greens[j].second)*(blues[k].second-greens[j].second));
                         d=d1+d2+d3;
                         if(d<distMin){
                              distMin=d;
                         }
                    }
               }
          }
          for(i=0;i<M;i++){
               d1=sqrtl((x-greens[i].first)*(x-greens[i].first)+(y-greens[i].second)*(y-greens[i].second));
               for(j=0;d1<distMin && j<N;j++){
                    d2=sqrtl((reds[j].first-greens[i].first)*(reds[j].first-greens[i].first)+(reds[j].second-greens[i].second)*(reds[j].second-greens[i].second));
                    for(k=0;(d1+d2<distMin) && k<K;k++){
                         d3=sqrtl((blues[k].first-reds[j].first)*(blues[k].first-reds[j].first)+(blues[k].second-reds[j].second)*(blues[k].second-reds[j].second));
                         d=d1+d2+d3;
                         if(d<distMin){
                              distMin=d;
                         }
                    }
               }
          }
          
          cout<<fixed<<setprecision(10)<<distMin<<'\n';
     }
     return 0;
}