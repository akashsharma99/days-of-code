/*
https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
print the bottom view of a binary tree
*/
void bottomView(Node *root)
{
    std::map<int,int> mp;
    queue<pair<Node*,int>> q;
    
    q.push(make_pair(root,0));
    while(!q.empty()){
        
        Node* temp=q.front().first;
        int pos=q.front().second;
        mp[pos]=temp->data;
        if(temp->left)
            q.push(make_pair(temp->left,pos-1));
        if(temp->right)
            q.push(make_pair(temp->right,pos+1));
        q.pop();
    }
    for (auto i=mp.begin(); i!=mp.end(); i++) { 
        cout<<(i->second)<<" "; 
    }
}