
import java.util.Queue;
import java.util.LinkedList;
class Queues
{
    Queue<Integer> q1 = new LinkedList<Integer>();
    Queue<Integer> q2 = new LinkedList<Integer>();
    
    /*The method pop which return the element poped out of the stack*/
    int pop()
    {
	    if(q1.isEmpty() && q2.isEmpty()){
	        return -1;
	    }
	    else if(q1.isEmpty()){
	        return q2.remove();
	    }
	    else{
	        return q1.remove();
	    }
    }
	
    /* The method push to push element into the stack */
    void push(int a)
    {
	    if(q1.isEmpty()){
	        q1.add(a);
	        while(!q2.isEmpty()){
	            q1.add(q2.remove());
	        }
	    }	
	    else{
	        q2.add(a);
	        while(!q1.isEmpty()){
	            q2.add(q1.remove());
	        }
	    }
    }
}