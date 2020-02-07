#include <bits/stdc++.h>
#define fastread std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;
int main(){
     fastread;
     int T,N,M,i,j;

     int inp,radpoint,geepoint;
     cin>>T;
     while(T>0){
          T--;
          radpoint=0;geepoint=0;
          cin>>N>>M;
          deque<int> rad;
          deque<int> gee;
          deque<int> st;
          for(i=0;i<N;i++){
               cin>>inp;
               rad.push_back(inp);
          }
          for(i=0;i<N;i++){
               cin>>inp;
               gee.push_back(inp);
          }
          for(i=0;i<M;i++){
               cin>>inp;
               st.push_back(inp);
          }
          while(!rad.empty()){
               if(rad.front()>gee.front()){
                    radpoint++;
                    if(!st.empty()){
                         rad.push_back(st.front());
                         st.pop_front();
                         gee.push_back(st.front());
                         st.pop_front();
                    }
               }
               else{
                    geepoint++;
                    if(!st.empty()){
                         gee.push_back(st.front());
                         st.pop_front();
                         rad.push_back(st.front());
                         st.pop_front();
                    }
               }
               rad.pop_front();
               gee.pop_front();
          }
          if(geepoint==radpoint){
               cout<<"Tie\n";
          }
          else if(geepoint>radpoint){
               cout<<"Geethakoomaree wins\n";
          }
          else{
               cout<<"Radhesh wins\n";
          }
     }
     return 0;
}