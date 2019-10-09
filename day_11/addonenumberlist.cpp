/*
https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
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