#include<bits/stdc++.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){
       int qt;
       cin>>qt;
       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }
}
/*returns min element from stack*/
int _stack :: getMin()
{
   if(!s.empty()){
        return s.top();
    }
    else{
        return -1;
    }
}
/*returns poped element from stack*/
int _stack ::pop()
{
   if(!s.empty()){
        s.pop();
        int t=s.top();
        s.pop();
        return t;
    }
    else{
        return -1;
    }
}
/*push element x into the stack*/
void _stack::push(int x)
{
   if(s.empty() || s.top()>x){
        s.push(x);
        s.push(x);
    }
    else{
        int t=s.top();
        s.push(x);
        s.push(t);
    }
}