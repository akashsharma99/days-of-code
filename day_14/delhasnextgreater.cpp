/*
Delete list nodes which have a greater node to its right.
https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1
Given a singly linked list, remove all the nodes which have a greater value on its next adjacent element.

1 <= size of linked list <= 100
1 <= element of linked list <= 1000
Example:
Input:
3
8
12 15 10 11 5 6 2 3
6
10 20 30 40 50 60
6
60 50 40 30 20 10
Output:
15 11 6 3
60
60 50 40 30 20 10
Explanation:
Testcase 1: Since, 12, 10, 5 and 2 are the elements which have greater elements on their next node. So, after deleting them, the linked list would like be 15, 11, 6, 3.
*/
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void rev(Node** head){
    if(*head==NULL)
    return;
    if((*head)->next==NULL){
        return;
    }
    Node* middle=*head;
    Node* left=NULL;
    Node* right=middle->next;
    
    while(right!=NULL){
        middle->next=left;
        left=middle;
        middle=right;
        right=right->next;
    }
    middle->next=left;
    *head=middle;
}
Node *compute(Node *head)
{
    rev(&head);
    
    Node* temp=head;
    while(temp!=NULL){
        Node* n=temp->next;
        while(n!=NULL && n->data<temp->data){
            n=n->next;
        }
        temp->next=n;
        temp=n;
    }
    rev(&head);
    return head;
}