/*
Implement queue using linked list
*/
class QueueNode
{
	int data;
	QueueNode next;
	QueueNode(int a)
	{
	    data = a;
	    next = null;
	}
}
class MyQueue
{
    QueueNode front, rear;
	void push(int a)
	{
        QueueNode node=new QueueNode(a);
        if(front==null){
            front=node;
            rear=node;
            return;
        }
        rear.next=node;
        rear=node;
        
	}
	
	int pop()
	{
        if(front==null){
            return -1;
        }
        int x=front.data;
        front=front.next;
        return x;
	}
}