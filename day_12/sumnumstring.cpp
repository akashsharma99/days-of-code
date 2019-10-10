/*
Input:
4
1abc23
geeks4geeks
1abc2x30yz67
123abc

Output:
24
4
100
123
*/
#include<iostream>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T!=0){
	    T--;
	    string st;
	    cin>>st;
	    st=st+"x";
	    int sum=0;
	    int num=0;
	    for(int i=0;i<st.length();i++){
	        if(st[i]>='0' && st[i]<='9'){
	            num=num*10+(int(st[i])-48);
	        }
	        else{
	            sum=sum+num;
	            num=0;
	        }
	    }
	    cout<<sum<<'\n';
	}
	return 0;
}