/*
CodeChef October Long challenge problem #3
not able to solve. 
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
     //added these two lines to make cin and cout behave as scanf and printf which are faster then normal cin and cout.
     ios_base::sync_with_stdio(false); 
     cin.tie(NULL);
	
     int T;
	cin>>T;
	while(T!=0){
	    T--;
	    vector<unsigned long long int> arr;
	    unsigned long long int N,K,i=0,j,a,b;
	    cin>>N>>K;
         while(i<N){
              i++;
              cin>>j;
              arr.push_back(j);
         }
         unsigned long long int x=(N%2==0)?N/2-1:N/2;
         for(i=0;i<=x;i++){
              a=arr[i%N];
              b=arr[N-(i%N)-1];
              arr[i%N]=a^b;
              arr[N-(i%N)-1]=a;
         }
         for(i=N;i<K;i++){
              a=arr[i%N];
              b=arr[N-(i%N)-1];
              arr[i%N]=a^b;
         }
         for(auto itr=arr.begin();itr!=arr.end();itr++){
              cout<<*itr<<" ";
         }
         cout<<"\n";
     }
     return 0;
}