import java.io.*;
class Solution
{
  public static void main(String args[])throws IOException
  {
    BufferedReader x=new BufferedReader(new InputStreamReader(System.in));
    int n=Integer.parseInt(x.readLine());
    long a[]=new long[n];
    for(int i=0;i<n;i++)
    {
      a[i]=Long.parseLong(x.readLine());

    }
    for(int i=0;i<n;i++)
    {
      long t=a[i];
      int ct=0,flag=0;
      if(t==1 || t==0)
      {
      }
      else
      {
        while(t>0)
        {
          if(t==1)
          {
            t=t/10;
            System.out.println("Yes");
            flag=1;
            break;
          }
          if(t%10==0)
          {
            ct++;
            t=t/10;
          }
          else
          {
            double lv=Math.log(t)/Math.log(2);
            if(Math.floor(lv)==Math.ceil(lv))
            {
              if(ct>=(int)lv)
              {
                System.out.println("Yes");
                flag=1;
                break;
              }
            }
            break;
          }
        }
      }
      if(flag==0)
        System.out.println("No");
    }
  }
}
