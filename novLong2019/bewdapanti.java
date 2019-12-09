import java.io.*;
class Hello{
     public static boolean checki(long numb){
          long temp=numb;
          long z=10;
          while(temp>0){
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
               temp=temp/10;
          }
          return true;
     }
     public static void main(String args[])throws IOException{
          FileWriter fw=new FileWriter("lol.txt");
          long count=0;
          for(long i=1;i<=30000000;i++){
               if(checki(i)){
                    fw.write(i+",");
                    count++;
               }
          }
          System.out.println(count);
          fw.close();
     }
}