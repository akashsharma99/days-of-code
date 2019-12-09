#include <bits/stdc++.h>
#define fastread std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ull unsigned long long int
#define uint unsigned int
using namespace std;
pair<int,int> getSum(int num){
     int s=0,d,count=0;
     while(num!=0){
          d=num%10;
          count++;
          s=s+(d*d);
          num=num/10;
     }
     return make_pair(s,count);
}
int main(){
     fastread;
     ull T,N,i,j,d,flg,flg2,sq;
     cin>>T;
     //creating an array of size 100 with sum of the digits of its index;
     int table[]={1,2,3,4,5,6,7,8,9,22,23,24,25,26,27,28,29,33,34,35,36,37,38,39,44,45,46,47,48,49,55,56,57,58,59,66,67,68,69,77,78,79,88,89,99,222,223,224,225,226,227,228,229,233,234,235,236,237,238,239,244,245,246,247,248,249,255,256,257,258,259,266,267,268,269,277,278,279,288,289,299,333,334,335,336,337,338,339,344,345,346,347,348,349,355,356,357,358,359,366,367,368,369,377,378,379,388,389,399,444,445,446,447,448,449,455,456,457,458,459,466,467,468,469,477,478,479,488,489,499,555,556,557,558,559,566,567,568,569,577,578,579,588,589,599,666,667,668,669,677,678,679,688,689,699,777,778,779,788,789,799,888,889,899,999};
     cout<<table[1]<<"/n";
     pair<int,int> sums[164];
for(i=0;i<165;i++){
     sums[i]=getSum(table[i]);
}
cout<<table[1]<<"\n";
     
     while(T>0){
          T--;
          cin>>N;
          if(N==1)
          {
               cout<<1<<"\n";
               continue;
          }
          flg=-1;
          for(i=0;i<165;i++){
               int Val=N-sums[i].second+sums[i].first;
               //now check if Val is a perfect square
               double root=floor(sqrt(Val));
               if(root*root==Val){
                    cout<<i<<table[i]<<" "<<sums[i].second<<" "<<sums[i].first<<"\n";
                    for(j=1;j<=N-sums[i].second;j++){
                         cout<<1;
                    }
                    
                    flg=0;
                    
               }
               
               if(flg==0){
                    if(i==0)
                         cout<<1;
                    else
                         cout<<table[i];
                    break;
               }
               
          }
          if(flg==-1)
          cout<<flg<<"\n";
          else
          cout<<"\n";
     }
     return 0;
}