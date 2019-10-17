// wap to implement priority scheduling algorithm for both preemptive and non preemptive
/*
a 0 3 3
b 0 4 8
c 4 8 3
d 4 5 2
*/

#include<stdio.h>
#include<malloc.h>
struct job{
     char jname;
     int priority;
     int bt;
     int arrival_time;
     int burst_time;
     int wait_time;
     int start_time;
}**jobs;
struct node{
     struct job* jb;
     struct node* prev;
     struct node* next;
}*queueHead,*queueLast;
void insertPriorityQueue(struct node** jnode){
     //struct job* jobb=(*jnode)->jb;
     struct node* temp=queueHead;
     if(queueHead==NULL){
          queueHead=*jnode;
          queueLast=*jnode;
          return;
     }
     //struct node* prev=temp;
     while(temp!=NULL && (temp->jb->priority)>=((*jnode)->jb->priority)){
          temp=temp->next;
     }
     if(temp==NULL){
          queueLast->next=*jnode;
          (*jnode)->prev=queueLast;
          queueLast=*jnode;
          return;
     }
     if(temp->prev==NULL){
          (*jnode)->next=queueHead;
          queueHead->prev=*jnode;
          queueHead=*jnode;
          return;
     }
     (*jnode)->prev=temp->prev;
     (*jnode)->next=temp;
     temp->prev->next=(*jnode);
     temp->prev=(*jnode);
     return;

}
int main(){
     int n;
     printf("How many jobs? ");
     scanf("%d",&n);
     jobs=(struct job**)calloc(n,sizeof(struct job*));
     printf("Enter %d job details in the format jobname arrival priority burst\n",n);
     //input all job details
     for(int i=1;i<=n;i++){
          fflush(stdin);
          jobs[i-1]=(struct job*)malloc(sizeof(struct job));
          scanf("%c%d%d%d",&(jobs[i-1]->jname),&(jobs[i-1]->arrival_time),&(jobs[i-1]->priority),&(jobs[i-1]->burst_time));
          jobs[i-1]->bt=jobs[i-1]->burst_time;
          jobs[i-1]->wait_time=0;
          jobs[i-1]->start_time=-1;        
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
     //display sorted jobs
     printf("jobs sorted according to arrival time\nname\tarrival\tpriority\tburst\n");
     for(int i=0;i<n;i++){
          printf("%c\t%d\t%d\t%d\n",jobs[i]->jname,jobs[i]->arrival_time,jobs[i]->priority,jobs[i]->burst_time);
     }
    
     //printf("Order of execution is..\n");
     printf("JOB\tSTART\tWAIT\tBURST\tEND\n");
     int timer=jobs[0]->arrival_time;
     queueHead=NULL;
     queueLast=NULL;
     int jindex=0,count=0;
     do{
          while(jindex<n && jobs[jindex]->arrival_time==timer )
          {
               struct node* jt=(struct node*)malloc(sizeof(struct node));
               jt->jb=jobs[jindex];
               jt->next=NULL;
               jt->prev=NULL;
               insertPriorityQueue(&jt);
               jindex++;
          }
          struct node* jFront=queueHead;
          if(jFront->jb->start_time==-1){
               jFront->jb->start_time=timer;
          }
          jFront->jb->wait_time+=timer-(jFront->jb->arrival_time);
          jFront->jb->burst_time--;
          timer++;
          jFront->jb->arrival_time=timer;
          if(jFront->jb->burst_time==0){
               count++;
               int st,end,wt,burst;
               st=jFront->jb->start_time;
               wt=jFront->jb->wait_time;
               end=timer;
               burst=jFront->jb->bt;
               printf("%c\t%d\t%d\t%d\t%d\n",jFront->jb->jname,st,wt,burst,end);
               queueHead=queueHead->next;
               if(queueHead)queueHead->prev=NULL;
          }
          // printf("The queue for timer%d  count%d\n",timer,count);
          // for(struct node* temp=queueHead;temp!=NULL;temp=temp->next){
          //      printf("%c__%d\n",temp->jb->jname,temp->jb->priority);
          // }
     }while(count<n);
     
     return 0;
}