
#include <bits/stdc++.h>
#define fastread std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;
int binaryToDecimal(string n) 
{ 
	string num = n; 
	int dec_value = 0; 

	// Initializing base value to 1, i.e 2^0 
	int base = 1; 

	int len = num.length(); 
	for (int i = len - 1; i >= 0; i--) { 
		if (num[i] == '1') 
			dec_value += base; 
		base = base * 2; 
	} 

	return dec_value; 
}
int main(){
     fastread;
     int T,N,i,j;
     int finalPlayer=0;
     string bin;
     cin>>T;
     while(T>0){
          T--;
          cin>>N;
          for(i=0;i<N;i++){
               cin>>bin;
               finalPlayer=finalPlayer^binaryToDecimal(bin);
          }
          unsigned int count = 0; 
          while (finalPlayer) 
          { 
               finalPlayer &= (finalPlayer-1) ; 
               count++; 
          }
          cout<<count<<'\n';
     }
     return 0;
}