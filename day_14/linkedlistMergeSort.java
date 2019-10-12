class Node
{
    int data;
    Node next;
    Node(int data)
    {
        this.data = data;
        next = null;
    }
}
class LinkList
{
    static Node sort(Node head)
    {
        if(head==null || head.next==null)
        return head;
        Node middle=getmiddle(head);
        Node right=middle.next;
        Node left=head;
        middle.next=null;
        left=sort(left);
        right=sort(right);
        head=merge(left,right);
        return head;
    }
    static Node merge(Node left,Node right){
        Node result;
        if(left==null)
        return right;
        if(right==null)
        return left;
        if(left.data<=right.data){
            result=left;
            result.next=merge(left.next,right);
        }
        else{
            result=right;
            result.next=merge(left,right.next);
        }
        return result;
    }
    static Node getmiddle(Node h){
        if(h==null)
        return h;
        Node slow=h,fast=h;
        while(fast.next!=null && fast.next.next!=null){
            fast=fast.next.next;
            slow=slow.next;
        }
        return slow;
    }
}