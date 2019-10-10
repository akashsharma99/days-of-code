/*
https://practice.geeksforgeeks.org/problems/next-larger-element/0
Find next greater element for each element in an array using stack
Input
2
4
1 3 2 4
4
4 3 2 1
Output
3 4 4 -1
-1 -1 -1 -1
*/
#include<iostream>
#include<stack>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T!=0){
	    T--;
	    int N;
	    cin>>N;
	    stack<int> st;
	    long long int arr[N];
	    long long int answer[N];
	    for(int i=0;i<N;i++){
	        cin>>arr[i];
	        answer[i]=-1;
	    }
	    for(int i=0;i<N;){
	        if(st.empty()||arr[st.top()]>arr[i]){
	            st.push(i);
	            i++;
	        }
	        else{
	            answer[st.top()]=arr[i];
	            st.pop();
	        }
	    }
	    for(int i=0;i<N;i++){
	        cout<<answer[i]<<" ";
	    }
	    cout<<'\n';
	}
}