/*
Find the maximum width of the binary tree
https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1
*/
int getMaxWidth(Node* root)
{
    if(root==NULL)
    return 0;
    int max=1;
   queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.front()!=NULL){
        Node* temp=q.front();
        int count=0;
        while(temp!=NULL){
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
            q.pop();
            count++;
            temp=q.front();
        }
        if(count>max)max=count;
        q.push(NULL);
        q.pop();
    }
    return max;
}