/*implement stack using linkedlist
*/
class StackNode
{
    int data;
    StackNode next;
    StackNode(int a)
    {
       data = a;
       next = null;
    }
}
class MyStack {
    // Note that top is by default null
    // in Java
    StackNode top;
    void push(int a) {
        StackNode node=new StackNode(a);
        if(top==null){
            top=node;
            return;
        }
        node.next=top;
        top=node;
    }
    int pop() {
        if(top==null)
        return -1;
        int x=top.data;
        top=top.next;
        return x;
    }
}