#include <bits/stdc++.h>
#define fastread std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;
struct CompareChef {
    bool operator()(list<int> const & a, list<int> const & b)
    { return a.front() < b.front(); }
};
int main(){
     fastread;
     int T,N,i,j,x,y;
     cin>>T;
     
     while(T>0){
          T--;
          cin>>N;
          vector<list<int>> prq;
          cin>>x;
          list<int> temp;
          for(j=0;j<x;j++){
               cin>>y;
               temp.push_back(y);
          }
          prq.push_back(temp);
          make_heap(prq.begin(),prq.end(),CompareChef());

          for(i=1;i<N;i++){//input and building the max heap of the given rows
               temp.erase(temp.begin(),temp.end());
               cin>>x;
               for(j=0;j<x;j++){
                    cin>>y;
                    temp.push_back(y);
               }
               prq.push_back(temp);
               push_heap(prq.begin(),prq.end(),CompareChef());
          }
          int turn=1;
          long long int chefMoney=0;
          while(!prq.empty()){
               if(turn){//chef's turn
                    //cout<<"Chef picked "<<prq.front().front()<<'\n';
                    chefMoney+=prq.front().front();
                    temp=prq.front();//first row in maxheap
                    pop_heap(prq.begin(),prq.end(),CompareChef());
                    prq.pop_back();
                    temp.pop_front();
                    if(!temp.empty()){//if row is not empty push it back to the heap
                         prq.push_back(temp);
                         push_heap(prq.begin(),prq.end(),CompareChef());
                    }
               }
               else{
                    vector<list<int>>::iterator it;
                    vector<list<int>>::iterator rowChosen;
                    rowChosen=prq.begin();
                    int coin=prq.front().back();
                    for(it = prq.begin(); it != prq.end(); ++it){//find iterator to required row
                         if(coin>(*it).back()){
                              coin=(*it).back();
                              rowChosen=it;
                         }
                    }
                    //now delete back of chosen row
                    temp=*rowChosen;
                    //cout<<"Opponent picked "<<temp.back()<<'\n';
                    temp.pop_back();
                    prq.erase(rowChosen);//remove row from heap
                    if(!temp.empty()){//if row is not empty push it back to the heap
                         prq.push_back(temp);
                    }
                    make_heap(prq.begin(),prq.end(),CompareChef());
               }
               turn=turn^1;
               // for(list<int> li : prq){
               //      for(int ele : li){
               //           cout<<ele<<" ";
               //      }
               //      cout<<endl;
               // }
          }
          cout<<"Chef's total money = "<<chefMoney<<endl;

     }

     return 0;
}