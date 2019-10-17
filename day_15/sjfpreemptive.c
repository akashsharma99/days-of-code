#include<stdio.h>
#include<malloc.h>
struct job{
     char jname;
     int status;
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
          jobs[i-1]->status=0;
          
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
     int i=0,bmin,timer=jobs[0]->arrival_time,cputime=0,start=0;
     int jobscompleted=0;
     printf("Order of execution is..\n");
     printf("JOB\tARRIVAL\tWAIT\tSTART\tEND\tBURST\n");
     while(jobscompleted<n){
          bmin=9999999;
          int jmin=-1;
          for(int j=0;j<n;j++){
               if(jobs[j]->status==0 && jobs[j]->arrival_time<=timer && jobs[j]->burst_time<bmin){
                    bmin=jobs[j]->burst_time;
                    jmin=j;
               }
               else if(jobs[j]->arrival_time>timer){
                    if(jmin==-1){
                         timer=jobs[j]->arrival_time;
                    }
                    break;
               }
          }
          if(jmin!=-1){
               for(i=0;i<n;i++){//searching for preemption
                    if(jobs[i]->arrival_time>timer && jobs[i]->arrival_time<(timer+(jobs[jmin]->burst_time)) )//ith job can preempt
                    {
                         int burstCompletedforjmin=jobs[jmin]->burst_time-(jobs[i]->arrival_time-timer);
                         int burstRemaining=jobs[jmin]->burst_time-burstCompletedforjmin
                    }

               }
               jobs[jmin]->status=1;
               jobscompleted++;
               start=timer;
               jobs[jmin]->wait_time=timer-(jobs[jmin]->arrival_time);
               timer+=jobs[jmin]->burst_time;
               cputime+=jobs[jmin]->burst_time;
               printf("%c\t%d\t%d\t%d\t%d\t%d\n",jobs[jmin]->jname,jobs[jmin]->arrival_time,jobs[jmin]->wait_time,start,timer,jobs[jmin]->burst_time);
          }
     }
     return 0;
}
