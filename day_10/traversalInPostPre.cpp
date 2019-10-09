void inOrder(Node* root)
{
  if(root!=NULL){
      inOrder(root->left);
      cout<<root->data<<" ";
      inOrder(root->right);
  }
}

void preorder(Node* root)
{
  if(root!=NULL){
      cout<<root->data<<" ";
      preorder(root->left);
      preorder(root->right);
  }
}

void postOrder(Node* root)
{
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}