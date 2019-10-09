int height(Node* node)
{
    if(node==NULL){
        return 0;
    }
   return 1+max(height(node->left),height(node->right));
}