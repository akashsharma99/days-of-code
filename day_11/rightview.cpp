/*
https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
print right view of the tree
*/
void leftView(Node *root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int d=0;
    while(q.front()!=NULL){
        Node* temp=q.front();
        while(temp!=NULL){
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
            q.pop();
            d=temp->data;
            temp=q.front();
        }
        cout<<d<<" ";
        q.push(NULL);
        q.pop();
    }
   // Your code here
}