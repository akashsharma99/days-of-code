/*
Level Order a Binary Tree using queue
https://practice.geeksforgeeks.org/problems/level-order-traversal/1
*/
void levelOrder(Node* node)
{
  queue<Node*> q;
  q.push(node);
  q.push(NULL);
  while(q.front()){
      
      Node* temp=q.front();
      while(temp!=NULL){
          cout<<temp->data<<" ";
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
}