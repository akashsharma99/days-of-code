/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substrings without repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”, with length 6.
Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is str.
Output:
Print the length of longest substring.
Constraints:
1 ≤ T ≤ 20
1 ≤ str ≤ 50
Example:
Input:
2
geeksforgeeks
qwertqwer
Output:
7
5*/
#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;
int main(){
     int T;
     cin>>T;
     while(T!=0){
          T--;
          string str;
          cin>>str;
          unordered_map<char,int> hmap;
          int start=0,max=0,len=0;
          set<int,greater<int>> lens;
          for(int i=0;i<str.length();i++){
               char ch=str[i];
               if(hmap.find(ch)==hmap.end()){
                    //key not found
                    hmap[ch]=i;
                    len++;
               }
               else{
                    lens.insert(len);
                    
                    //cout<<len<<"..."<<str.substr(start,start+len)<<endl;
                    int p=hmap[ch],k=p;
                    while(k>=start){
                         hmap.erase(str[k]);
                         k--;
                    }
                    start=p+1;
                    len=i-start+1;
                    
                    
                    hmap[ch]=i;
               }
          }
          lens.insert(len);
          cout<<*(lens.begin())<<endl;
     }
     return 0;
}