
#include <bits/stdc++.h>
#define fastread std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
int main()
{
	fastread;
    	int t,N,i,j;
     long long int sol,n,K,Rcount,Lcount;
    	cin>>t;
    	while(t--)
    	{
          Lcount=0;
          Rcount=0;
        	vector<long long int> arr;
          cin>>N>>K;
          for(i=0;i<N;i++){
               cin>>n;
               arr.push_back(n);
          }

          for(i=0;i<N;i++){
               //left count
               for(j=i-1;j>=0;j--){
                    if(arr[j]<arr[i])
                    Lcount++;
               }
               //right count
               for(j=i+1;j<N;j++){
                    if(arr[j]<arr[i])
                    Rcount++;
               }
          }
          sol=Rcount*K*(K+1)/2 + Lcount*(K-1)*K/2;
          cout<<sol<<"\n";
    	}
     return 0;
}