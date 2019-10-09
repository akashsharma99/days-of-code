int countLeaves(Node* root)
{
  if(root!=NULL){ 
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        int leafL=0,leafR=0;
        if(root->left!=NULL){
            leafL=countLeaves(root->left);
        }
        if(root->right!=NULL){
            leafR=countLeaves(root->right);
        }
        return leafL+leafR;
  }
}
int countNonLeafNodes(Node* root)
{
    if(root!=NULL){ 
        if(root->left==NULL && root->right==NULL){
            return 0;
        }
        int leafL=0,leafR=0;
        if(root->left!=NULL){
            leafL=countNonLeafNodes(root->left);
        }
        if(root->right!=NULL){
            leafR=countNonLeafNodes(root->right);
        }
        return 1+leafL+leafR;
  }
}