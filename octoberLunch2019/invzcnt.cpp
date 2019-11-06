#include <bits/stdc++.h>
#include<algorithm>
#define fastread std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;
int getSum(long long int BITree[], long long int index) 
{ 
    long long int sum = 0; // Initialize result 
  
    // Traverse ancestors of BITree[index] 
    while (index > 0) 
    { 
        // Add current element of BITree to sum 
        sum += BITree[index]; 
  
        // Move index to parent node in getSum View 
        index -= index & (-index); 
    } 
    return sum; 
} 
  
// Updates a node in Binary Index Tree (BITree) at given index 
// in BITree.  The given value 'val' is added to BITree[i] and 
// all of its ancestors in tree. 
void updateBIT(long long int BITree[],long long int n,long long int index,long long int val) 
{ 
    // Traverse all ancestors and add 'val' 
    while (index <= n) 
    { 
       // Add 'val' to current node of BI Tree 
       BITree[index] += val; 
  
       // Update index to that of parent in update View 
       index += index & (-index); 
    } 
} 
  
// Returns inversion count arr[0..n-1] 
int getInvCount(long long int arr[], long long int n) 
{ 
    long long int invcount = 0; // Initialize result 
  
    // Find maximum element in arr[] 
    long long int maxElement = 0; 
    for (int i=0; i<n; i++) 
        if (maxElement < arr[i]) 
            maxElement = arr[i]; 
  
    // Create a BIT with size equal to maxElement+1 (Extra 
    // one is used so that elements can be directly be 
    // used as index) 
    long long int BIT[maxElement+1]; 
    for (int i=1; i<=maxElement; i++) 
        BIT[i] = 0; 
  
    // Traverse all elements from right. 
    for (int i=n-1; i>=0; i--) 
    { 
        // Get count of elements smaller than arr[i] 
        invcount += getSum(BIT, arr[i]-1); 
  
        // Add current element to BIT 
        updateBIT(BIT, maxElement, arr[i], 1); 
    } 
  
    return invcount; 
} 
int main()
{
	fastread;
    	int t,i,j;
     long long int N,sol,n,K,Q,Rcount;
    	cin>>t;
    	while(t--)
    	{
          cin>>N>>Q;
          long long int arr[N];
          
          for(i=0;i<N;i++){
               cin>>arr[i];
          }

          for(i=0;i<Q;i++){
               long long int arrcpy[N];
               cin>>K;
               for(j=0;j<N;j++){
                    arrcpy[j]=arr[j]^K;
               }
               
               Rcount=getInvCount(arrcpy,N);
               cout<<Rcount<<'\n';
          }
    	}
     return 0;
}