/*
https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1
Traverse a tree in spiral order
Testcase1: The tree is
        1
     /      \
   3       2
So, the spiral level order would be 1 3 2
Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \
               40       60
So, the spiral level order would be 10 20 30 60 40
*/
int heightOfTree(Node* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(heightOfTree(root->left),heightOfTree(root->right));
}
void printGivenLevel(Node* root, int level,int p){
    if(root==NULL)
    return;
    if(level==1)
    cout<<root->data<<" ";
    else{
        if(p%2==0){
            printGivenLevel(root->left, level-1, p);
            printGivenLevel(root->right, level-1, p);
        }
        else{
            printGivenLevel(root->right, level-1, p);
            printGivenLevel(root->left, level-1, p);
        }
    }
}

void printSpiral(Node *root)//call this from main
{
    int height=heightOfTree(root);
    for(int d=1;d<=height;d++){
        printGivenLevel(root,d,d);
    }
}