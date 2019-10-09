/*
Print the kth node from root OR print all nodes of level K
https://practice.geeksforgeeks.org/problems/k-distance-from-root/1
*/
void printKdistance(Node *root, int k)
{
    if(root==NULL || k<0)
    return;
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printKdistance(root->left,k-1);
    printKdistance(root->right,k-1);
}