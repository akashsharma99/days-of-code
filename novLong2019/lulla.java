import java.io.*;
import java.util.ArrayList;
class Hello{
     
     public static void main(String args[])throws IOException{
          FileWriter fw=new FileWriter("naya.txt");
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
          int xx=1,yy=9,pp=1,countt=0;
          for(int kk=0;kk<50;kk++){
               for(int ii=xx;ii<yy;ii++){
                    for(int jj=1;jj<=8;jj++){
                         if(li.get(jj)>=(li.get(ii)%10)){
                              long ev=(li.get(ii))*((long)Math.pow(10,pp))+li.get(jj);
                              fw.write(ev+"\n");
                              li.add(ev);
                              countt++;
                         }
                    }
                    xx=yy;
                    yy=yy+countt;
               }
               pp=pp+1;    
          }
          System.out.println(countt);
          fw.close();
     }
}