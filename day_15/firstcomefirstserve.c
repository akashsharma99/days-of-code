#include<stdio.h>
#include<malloc.h>
struct job{
     char jname;
     int arrival_time;
     int burst_time;
     int wait_time;
}**jobs;
int main(){
     int n;
     printf("How many jobs? ");
     scanf("%d",&n);
     jobs=(struct job**)calloc(n,sizeof(struct job*));
     printf("Enter %d job details in the format jobname<space>arrival<space>burst\n",n);
     for(int i=1;i<=n;i++){
          fflush(stdin);
          jobs[i-1]=(struct job*)malloc(sizeof(struct job));
          scanf("%c%d%d",&(jobs[i-1]->jname),&(jobs[i-1]->arrival_time),&(jobs[i-1]->burst_time));
          
     }
//sort the jobs wrt arrival time
     for(int i=0;i<n;i++){
          for(int j=0;j<n-i-1;j++){
               if(jobs[j]->arrival_time>jobs[j+1]->arrival_time){
                    struct job* temp= jobs[j];
                    jobs[j]=jobs[j+1];
                    jobs[j+1]=temp;
               }
          }
     }
     int timer=0,cputime=0,start=0;
     printf("Order of execution is..\n");
     printf("JOB\tARRIVAL\tWAIT\tSTART\tEND\tBURST\n");
     for(int i=0;i<n;i++){
          if(timer>=jobs[i]->arrival_time){
               start=timer;
               jobs[i]->wait_time=timer-(jobs[i]->arrival_time);
               timer+=jobs[i]->burst_time;
               cputime+=jobs[i]->burst_time;
               printf("%c\t%d\t%d\t%d\t%d\t%d\n",jobs[i]->jname,jobs[i]->arrival_time,jobs[i]->wait_time,start,timer,jobs[i]->burst_time);
          }
          else{
               start=jobs[i]->arrival_time;
               jobs[i]->wait_time=0;
               timer=jobs[i]->arrival_time+jobs[i]->burst_time;
               cputime+=jobs[i]->burst_time;
               printf("%c\t%d\t%d\t%d\t%d\t%d\n",jobs[i]->jname,jobs[i]->arrival_time,jobs[i]->wait_time,start,timer,jobs[i]->burst_time);
          }
     }
     return 0;
}
