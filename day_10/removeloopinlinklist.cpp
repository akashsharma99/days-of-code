void removeTheLoop(Node *head)
{
    unordered_set<Node*> visited;
    while(head){
        visited.insert(head);
        if(visited.find(head->next)!=visited.end()){
            head->next=NULL;
        }
        
        head=head->next;
    }
}