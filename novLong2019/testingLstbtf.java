import java.io.*;
class Solution
{
     static int sums[][]=new int[1000][2];
     static ArrayList<Integer>  arrlist=new ArrayList<Integer>();
     static int table[]={1,2,3,4,5,6,7,8,9,22,23,24,25,26,27,28,29,33,34,35,36,37,38,39,44,45,46,47,48,49,55,56,57,58,59,66,67,68,69,77,78,79,88,89,99,222,223,224,225,226,227,228,229,233,234,235,236,237,238,239,244,245,246,247,248,249,255,256,257,258,259,266,267,268,269,277,278,279,288,289,299,333,334,335,336,337,338,339,344,345,346,347,348,349,355,356,357,358,359,366,367,368,369,377,378,379,388,389,399,444,445,446,447,448,449,455,456,457,458,459,466,467,468,469,477,478,479,488,489,499,555,556,557,558,559,566,567,568,569,577,578,579,588,589,599,666,667,668,669,677,678,679,688,689,699,777,778,779,788,789,799,888,889,899,999};
public static void getSum(int i){
     int num=table[i];
     int s=0,d,count=0;
     while(num!=0){
          d=num%10;
          count++;
          s=s+(d*d);
          num=num/10;
     }
     sums[i][0]=s;
     sums[i][1]=count;
}
public static void foo(){
     for(int i=0;;i++){
          if(i<165){
               arrlist.add(table[i]);
          }
          else{
               for(int j=9;j<=44;j++){
                    arrList.add(22*100+table[j]);
               }
          }
     }
}
public static int sumstring(String s){
     int x=0;
     for(int i=0;i<s.length();i++){
          int d=((int)s.charAt(i))-48;
          x=x+(d*d);
     }
     return x;
}
  public static void main(String args[])throws IOException
  {
    BufferedReader x=new BufferedReader(new InputStreamReader(System.in));
    FileWriter fw=new FileWriter("output1.txt");
    int N,i,j,flg;
    for(i=0;i<166;i++){
          getSum(i);
    }
    int T=Integer.parseInt(x.readLine());
    
    
    while(T>0){
     T--;
     N=T;
     fw.write(N+" ");
     if(N==1)
     {
          fw.write("1\n");
          continue;
     }
     flg=-1;String st="";
     int pk=0;
     for(i=0;i<166;i++){
          int Val=N-sums[i][1]+sums[i][0];
          //now check if Val is a perfect square
          double root=Math.floor(Math.sqrt(Val));
          if(root*root==Val){
               for(j=1;j<=N-sums[i][1];j++){
                    st=st+"1";
               }
               flg=0;
          }
          if(flg==0){
               if(i==0)
               st=st+"1";
               else
                    st=st+table[i];

               pk=sumstring(st);
               st=st+" "+pk+"\n";
               fw.write(st);
               break;
          }
          
     }
     if(flg==-1){
     st=st+flg+"\n";
     fw.write(st);
     }
     
}
fw.close();
  }
}
