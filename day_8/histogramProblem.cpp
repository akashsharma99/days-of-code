/*
This is the histogram problem where you have to find the largest rectangle you can make in a histogram
*/
#include<iostream>
#include<stack>
using namespace std;
int main()
 {	
	unsigned long long int n,max,greatest=0;
	int T;
	cin>>T;
	while(T!=0){
	    T--;
	    int N,i=0;
	    cin>>N;
	    unsigned long long int elements[N];
	    stack<int> positions;
	    greatest=0;
	    while(i<N){
	        cin>>elements[i];
	        i++;
	    }
	    i=0;
	    while(i<N){
	        if(positions.empty()||elements[positions.top()]<=elements[i]){
	            positions.push(i++);
	        }
	        else{
	            int topPos=positions.top();
	            positions.pop();
	            if(positions.empty())
	                max=elements[topPos]*i;
	            else
	                max=elements[topPos]*(i-positions.top()-1);
	            
	            if(max>greatest){
	                greatest=max;
	            }
	        }
	    }
	    while(!positions.empty()){
	        int topPos=positions.top();
	            positions.pop();
	            if(positions.empty())
	                max=elements[topPos]*i;
	            else
	                max=elements[topPos]*(i-positions.top()-1);
	            
	            if(max>greatest){
	                greatest=max;
	            }
	    }
	    cout<<greatest<<'\n';	    
	}
	return 0;
}