/*
https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

A number (n) is represented in Linked List such that each digit corresponds to a node in linked list. Add 1 to it.

Input:
You have to complete the method which takes one argument: the head of the linked list. You should not read any input from stdin/console.. There are multiple test cases. For each test case, this method will be called individually

Output:
Your function should return pointer to head of the modified list.

Constraints:
1 <=T<= 50
1 <=n<= 10000

Example:

Input:
4
456
123
999
1879

Output:
457 
124 
1000 
1880
*/

Node *addOne(Node *head)
{
    int num=0;
    Node* temp=head;
    while(temp!=NULL){
        num=num*10+temp->data;
        temp=temp->next;
        
    }
    num=num+1;
    string n=to_string(num);
    int i=0;
    for(temp=head;(i<n.length()) && temp!=NULL;i++,temp=temp->next){
        temp->data=int(n[i])-48;
        if((temp->next)==NULL && (i+1)<n.length()){
            temp->next=(Node*)malloc(sizeof(Node));
            temp->next->next=NULL;
        }
    }
    return head;
}