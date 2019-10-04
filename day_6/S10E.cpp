/*Chef wants to buy a new phone, but he is not willing to spend a lot of money. Instead, he checks the price of his chosen model everyday and waits for the price to drop to an acceptable value. So far, he has observed the price for N days (numbere 1 through N); for each valid i, the price on the i-th day was Pi dollars.

On each day, Chef considers the price of the phone to be good if it is strictly smaller than all the prices he has observed during the previous five days. If there is no record of the price on some of the previous five days (because Chef has not started checking the price on that day yet), then Chef simply ignores that previous day ― we could say that he considers the price on that day to be infinite.

Now, Chef is wondering ― on how many days has he considered the price to be good? Find the number of these days.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers P1,P2,…,PN.
Output
For each test case, print a single line containing one integer ― the number of days with a good price.

Constraints
1≤T≤100
7≤N≤100
350≤Pi≤750 for each valid i
Subtasks
Subtask #1 (30 points): N=7
Subtask #2 (70 points): original constraints

Example Input
1
7
375 750 723 662 647 656 619
Example Output
2
Explanation
Example case 1: Chef considers the price to be good on day 1, because he has not observed any prices on the previous days. The prices on days 2,3,4,5,6 are not considered good because they are greater than the price on day 1. Finally, the price on day 7 is considered good because it is smaller than all of the prices on days 2,3,4,5,6.
*/
#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T!=0){
	    T--;
	    list<int> arr;
	    int N;
	    cin>>N;
         int n;
         int good=0;
	    while(N!=0){
	        N--;
	        cin>>n;
	        if(arr.size()==0){
                  arr.push_back(n);
                  good++;
             }
             else if(arr.size()<5){
                  int minele=*(std::min_element(arr.begin(),arr.end()));
                  if(n<minele){
                       good++;
                  }
                  arr.push_back(n);
             }
             else{
                  int minele=*(std::min_element(arr.begin(),arr.end()));
                  arr.pop_front();
                  if(n<minele){
                       good++;
                  }
                  arr.push_back(n);
             }
	    }
	    cout<<good<<endl;
	}
	return 0;
}