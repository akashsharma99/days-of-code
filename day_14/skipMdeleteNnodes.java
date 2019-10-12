class Node
  {
      int data;
      Node next;
      Node(int data)
      {
          this.data = data;
          this.next = null;
      }
  }
*/
class Solution
{
    static void linkdelete(Node head, int M, int N)
    {
        int a,b;
        Node curr=head,skip=head.next;
        while(curr!=null && skip!=null){
            a=M;
            b=N;
            while(a>1 && curr!=null){
                curr=curr.next;
                a--;
            }
            if(curr==null)
            break;
            skip=curr.next;
            while(b>=1 && skip!=null){
                skip=skip.next;
                b--;
            }
            curr.next=skip;
            curr=curr.next;
        }
    }
}