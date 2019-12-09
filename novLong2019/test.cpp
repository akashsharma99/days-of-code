#include <functional>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

struct CompareChef {
    bool operator()(vector<int> const & a, vector<int> const & b)
    { return a[0] < b[0]; }
};

int main()
{

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    vector<vector<int>> pr_q;

    int a[5] = { 1,2,3,4 };
    v1.insert(v1.end(), a, a+4); v1[0] = 11; // v1 = {1, 2, 11, 4}
    v2.insert(v2.end(), a, a+4); v2[0] = -1; // v1 = {1, 2, -1, 4}
    v3.insert(v3.end(), a, a+4); v3[0] = 22; // v1 = {1, 2, 22, 4}
    v4.insert(v4.end(), a, a+4); v4[0] = 31; // v1 = {1, 2, 31, 4}

    pr_q.push_back(v1);
    pr_q.push_back(v2);
    pr_q.push_back(v3);
    pr_q.push_back(v4);
    make_heap(pr_q.begin(),pr_q.end(),CompareChef());
     for(auto i=pr_q.begin();i!=pr_q.end();i++){
          cout<<(*i)[0]<<endl;
     }
    

    return 0;
}