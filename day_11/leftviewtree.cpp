/*
https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
Left view of following tree is 1 2 4 8.

         1
       /   \
     2      3
   /  \    / \
  4    5  6   7
      /
     8
*/
void leftView(Node *root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.front()!=NULL){
        cout<<q.front()->data<<" ";
        Node* temp=q.front();
        while(temp!=NULL){
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
            q.pop();
            temp=q.front();
        }
        q.push(NULL);
        q.pop();
    }
   // Your code here
}