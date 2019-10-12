/*
https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
reverse a linked list in groups
*/
class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}
class GfG
{
    public static Node reverse(Node node, int k)
    {
        int flg=0;
        Node temp=node,start=node,tr=null;
        Stack<Node> stack=new Stack<Node>();
        while(temp!=null){
            int i=k;
            while(i>0 && temp!=null){
                stack.push(temp);
                temp=temp.next;
                i--;
            }
            if(flg==0)//firsttime
            {
                start=stack.peek();
                tr=start;
                flg=1;
            }
            while(!stack.empty()){
                tr.next=stack.pop();
                tr=tr.next;
            }
        }
        tr.next=null;
        return start;
    }
}
