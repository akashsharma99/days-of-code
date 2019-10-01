/*Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.

Input:  
The first line of the input contains T denoting the number of testcases. The first line of the test case will be the size of array and second line will be the elements of the array.

Output: 
For each test case the output will be the majority element of the array. Output "-1" if no majority element is there in the array.

Constraints:
1 <= T<= 100
1 <= N <= 107
0 <= Ai <= 106

Example:
Input:
2
5
3 1 3 3 2
3
1 2 3

Output:
3
-1

Explanation:
Testcase 1: Since, 3 is present more than N/2 times, so it is the majority element.
 */


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
	int T,N,temp,k;
	unordered_map<int,int> mp;
	cin>>T;
	while(T>0){
	    T--;
	    cin>>N;
	    int found=0;
	    for(int i=0;i<N;i++){
              cin>>temp;
              mp[temp]++;
              //cout<<"mp"<<temp<<"="<<mp[temp]<<"___";
              if(found==0 && mp[temp]>N/2){
                   cout<<temp<<endl;
                   found=1;
              }
         }
         if(found==0){
              cout<<-1<<endl;
         }
         mp.erase(mp.begin(),mp.end());
     }
     return 0;
}