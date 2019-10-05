/*

Codechef October Long Challenge 2019 problem #4

You are given a sequence A1,A2,…,AN. For each valid i, the star value of the element Ai is the number of valid indices j<i such
that Aj is divisible by Ai.
Chef is a curious person, so he wants to know the maximum star value in the given sequence. Help him find it.
Input
The first line of the input contains a single integer T which denotes the number of test cases.
The first line of each test case contains a single integer N .
The second line of each test case contains N space-separated integers A1,A2,…,AN.
Output
For each test case, print a single line containing one integer ― the maximum star value.

Constraints
1≤T≤10
1≤N≤105
1≤Ai≤106 for each valid i
Sum of N over all test cases does not exceed 100,000.
Subtasks
Subtask #1 (20 points): sum of N over all test cases does not exceed 5,000
Subtask #2 (80 points): original constraints

Example Input
1
7
8 1 28 4 2 6 7
Example Output
3
Explanation
A5=2 divides 4, 28 and 8, so its star value is 3. There is no element with a higher star value.

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
	    vector<int> arr;
	    int N,i=0,j;
	    cin>>N;
         while(i<N){
              i++;
              cin>>j;
              arr.push_back(j);
         }
         int max=0;
         for(i=N-1;i>0;i--){
              int cp=0;
              for(j=i-1;j>=0;j--){
                   if(arr[j]%arr[i]==0){
                        cp++;
                   }
                   if(max-cp>j){
                        //cout<<arr[j]<<"<-j\n"<<arr[i]<<"<-i"<<endl;
                        break;
                   }
              }
              if(cp>max){
                   max=cp;
              }
         }
         cout<<max<<endl;
     }
     return 0;
}
