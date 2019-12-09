import java.io.*;
import java.util.*;
class Solution
{
     static long sums,digits;
     //static int table[];
     
     public static boolean getSum(long i){
     long temp=i;
     long z=10;
     long s=0,count=0;
     while(temp!=0){
          if(temp%10==1){
               return false;
          }
          if(temp%10==0){
               return false;
          }
          if(temp%10>z){
               return false;
          }
          z=temp%10;
          count++;
          s=s+(z*z);
          temp=temp/10;
     }
     sums=s;
     digits=count;
     return true;
}
  public static void main(String args[])throws IOException
  {
    BufferedReader x=new BufferedReader(new InputStreamReader(System.in));
    int N,flg;
    long i,j;
    
    int T=Integer.parseInt(x.readLine());
    ArrayList<Long> li=new ArrayList<Long>();
          li.add(1L);
          li.add(2L);
          li.add(3L);
          li.add(4L);
          li.add(5L);
          li.add(6L);
          li.add(7L);
          li.add(8L);
          li.add(9L);
    
     while(T>0){
          T--;
          N=Integer.parseInt(x.readLine());
          if(N==1)
          {
               System.out.println(1);
               continue;
          }
          //when N is perfect square
          double root=Math.floor(Math.sqrt(N));
               if(root*root==N){
                    for(j=1;j<=N;j++){
                         System.out.print(1);
                    }
                    System.out.println();
                    continue;
               }


          flg=-1;
          for(i=1;i<9;i++){
               if(getSum(li.get((int)i))==false){
                    continue;
               }
               long Val=N-digits+sums;
               //now check if Val is a perfect square
               root=Math.floor(Math.sqrt(Val));
               if(root*root==Val){
                    for(j=1;j<=N-digits;j++){
                         System.out.print(1);
                    }
                    flg=0;
               }
               if(flg==0){
                    if(Val==N)
                    System.out.println(1);
                    else
                    System.out.println(li.get((int)i));
                    break;
               }
               
          }
          if(flg==0)
          continue;

          int xx=1,yy=9,pp=1,countt=0;
          for(int kk=0;kk<10;kk++){
               for(int ii=xx;ii<yy;ii++){
                    for(int jj=1;jj<=8;jj++){
                         if(li.get(jj)>=(li.get(ii)%10)){
                              long ev=(li.get(ii))*((long)Math.pow(10,pp))+li.get(jj);
                              //fw.write(ev+"\n");
                              li.add(ev);
                              countt++;
                              if(getSum(ev)==false){
                                   continue;
                              }
                              long Val=N-digits+sums;
                              //now check if Val is a perfect square
                              root=Math.floor(Math.sqrt(Val));
                              if(root*root==Val){
                                   for(j=1;j<=N-digits;j++){
                                        System.out.print(1);
                                   }
                                   flg=0;
                              }
                              if(flg==0){
                                   if(Val==N)
                                   System.out.println(1);
                                   else
                                   System.out.println(ev);
                                   break;
                              }
                              if(flg==0)break;
                         }
                         if(flg==0)break;
                    }
                    if(flg==0)break;
                    xx=yy;
                    yy=yy+countt;
               }
               if(flg==0)break;
               pp=pp+1;    
          }
          
          if(flg==-1)
          System.out.println(flg);
     }
  }
}
