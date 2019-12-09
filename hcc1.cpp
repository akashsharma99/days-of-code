#include <bits/stdc++.h>
#define fastread std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;


int main() {
    fastread;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned long long int T,N,copy,pages,extraorigin;
    cin>>T;
    while(T--){
        //T--;
        cin>>N;
        //copy=N;
        pages=0;
        if(N<=128){
             cout<<1<<"\n";
        }
        else{
            while(N>=123){
            N=N-123;
            //cout<<N<<"\n";
            pages++;
          }
          cout<<pages+1<<"\n";
        }
        
        /*extraorigin=(N/123)
        N=N+((N/128)*5);
        //cout<<N<<"..."<<endl;
        
        pages=ceil(N/128.0);
        //cout<<pages<<endl;
        if(pages==0){
            cout<<1<<"\n";
        }
        else{
            cout<<pages<<"\n";
        }*/
       
    }
    return 0;
}
