#include<stdio.h>
#include<malloc.h>
struct job{
     char jname;
     int arrival_time;
     int burst_time;
     int wait_time;
}**jobs;
void sortJobs(struct job** jobs,int n){
     for(int i=0;i<n;i++){
          for(int j=0;j<n-i-1;j++){
               if(jobs[j]->arrival_time>jobs[j+1]->arrival_time){
                    struct job* temp= jobs[j];
                    jobs[j]=jobs[j+1];
                    jobs[j+1]=temp;
               }
          }
     }
}
int findMinArrival(struct job** jobs,int n){
     int minarr=jobs[0]->arrival_time,index=0;
     for(int i=0;i<n;i++){
          if(jobs[i]->arrival_time<minarr){
               minarr=jobs[i]->arrival_time;
               index=i;
          }
     }
     return index;
}
int main(){
     int n,quanta;
     printf("How many jobs? ");
     scanf("%d",&n);
     jobs=(struct job**)calloc(n,sizeof(struct job*));
     printf("Enter %d job details in the format jobname<space>arrival<space>burst\n",n);
     for(int i=1;i<=n;i++){
          fflush(stdin);
          jobs[i-1]=(struct job*)malloc(sizeof(struct job));
          scanf("%c%d%d",&(jobs[i-1]->jname),&(jobs[i-1]->arrival_time),&(jobs[i-1]->burst_time));
          jobs[i-1]->wait_time=0;
          
     }
     printf("enter qanta value: ");
     scanf("%d",&quanta);     
     printf("Order of execution is..\n");
     printf("JOB\tSTART\tEND\tBURSTremain\n");
     int completed=0;
     int index=findMinArrival(jobs,n);
     int timer=jobs[index]->arrival_time,cputime=0,start=timer;
     int tot=n;
     while(completed<tot){
          //sortJobs(jobs,n);
          index=findMinArrival(jobs,n);
          jobs[index]->wait_time+=timer-jobs[index]->arrival_time;
          int burst=(quanta<jobs[index]->burst_time)?quanta:jobs[index]->burst_time;
          timer=timer+burst;
          jobs[index]->arrival_time=timer;
          jobs[index]->burst_time-=burst;
          printf("%c\t%d\t%d\t%d\n",jobs[index]->jname,jobs[index]->arrival_time-burst,timer,jobs[index]->burst_time);
          if(jobs[index]->burst_time<=0){
               completed++;
               jobs[index]=jobs[n-1];
               n--;
               
          }
     }
     return 0;
}
