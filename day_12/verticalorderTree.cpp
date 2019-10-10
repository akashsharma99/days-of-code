/*
https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
Print the tree in vertical order traversal
Testcase1:
         1
       /     \
    2         3
              /
         5
As it is evident from the above diagram that during vertical traversal 2 will come first, then 1 and  5, and then 3. So output is 2 1 5 3
Testcase2:
         1
       /     \
     3       2
As it is evident from the above diagram that during vertical traversal 3 will come first, then 1 and then 2. So output is 3 1 2
*/
void verticalOrder(Node *root)
{
    std::map<int,vector<int>> mp;
    queue<pair<Node*,int>> q;
    
    q.push(make_pair(root,0));
    while(!q.empty()){
        
        Node* temp=q.front().first;
        int pos=q.front().second;
        mp[pos].push_back(temp->data);
        if(temp->left)
            q.push(make_pair(temp->left,pos-1));
        if(temp->right)
            q.push(make_pair(temp->right,pos+1));
        q.pop();
    }
    for (auto i=mp.begin(); i!=mp.end(); i++) { 
        vector<int> v=i->second;
        for(int x:v){
            cout<<x<<" ";
        }
    }
}