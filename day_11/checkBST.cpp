/*
https://practice.geeksforgeeks.org/problems/check-for-bst/1
Program to check weather a given binary tree is a BST
*/


bool checkBST(Node* root,int min,int max){
    if(root==NULL)
    return true;
    if((root->data)<min || (root->data)>max)
    return false;
    
    return checkBST(root->left,min,(root->data)-1) && checkBST(root->right,(root->data)+1,max);
}
bool isBST(Node* root) {
    return checkBST(root,INT_MIN,INT_MAX);
}