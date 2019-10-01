class Node{
    int data;
    Node next;
    Node(int d){
        data=d;
        next=null;
    }
}

class Rotate {
    
     /*  This function should rotate list counter-
    clockwise by k and return new head (if changed) */
    public Node rotate(Node head, int k) {
        Node temp=head;
        for(int i=1;i<k;i++){
            temp=temp.next;
        }
        Node last=temp;
        while(last.next!=null){
            last=last.next;
        }
        last.next=head;
        head=temp.next;
        temp.next=null;
        return head;
        
    }
}