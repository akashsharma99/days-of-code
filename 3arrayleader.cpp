/*Given an array of positive integers. Your task is to find the leaders in the array.
Note: An element of array is leader if it is greater than or equal to all the elements to its right side. Also, the rightmost element is always a leader. 

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the size of array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print all the leaders.

Constraints:
1 <= T <= 100
1 <= N <= 107
0 <= Ai <= 107

Example:
Input:
3
6
16 17 4 3 5 2
5
1 2 3 4 0
5
7 4 5 7 3
Output:
17 5 2
4 0
7 7 3*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	int T,N,temp,k;
	cin>>T;
	while(T>0){
	    T--;
	    cin>>N;
         stack<int> st;
         int arr[N];
         
	    for(int i=0;i<N;i++){
              cin>>arr[i];
         }
         int high=arr[N-1];
         for(int i=N-1;i>=0;i--){
              if(arr[i]>=high){
                   st.push(arr[i]);
                   high=arr[i];
              }
         }
         while(!st.empty()){
              cout<<st.top()<<" ";
              st.pop();
         }
         cout<<endl;

     }
     return 0;
}