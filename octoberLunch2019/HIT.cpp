
#include <bits/stdc++.h>
#define fastread std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
int main()
{
	fastread;
    	int t,N,i,j,n;
    	cin>>t;
    	while(t--)
    	{
        	vector<int> arr;
          int x=-1,y=-1,z=-1;
          cin>>N;
          for(i=0;i<N;i++){
               cin>>n;
               arr.push_back(n);
          }
          sort(arr.begin(),arr.end());
          x=arr[N/4];
          y=arr[N/2];
          z=arr[3*(N/4)];
          if(x>arr[(N/4)-1] && y>arr[(N/2)-1] && z>arr[((N/4)*3)-1])
               cout<<x<<" "<<y<<" "<<z<<'\n';
          else
               cout<<-1<<'\n';
    	}
     return 0;
}