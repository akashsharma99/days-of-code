// wap to implement priority scheduling algorithm for both preemptive and non preemptive
/*
a 3 9 10
b 2 10 11
c 3 8 1
d 1 3 2
e 1 4 1
f 2 2 10
g 3 14 20
h 0 13 9
*/

#include<stdio.h>
#include<malloc.h>
struct job{
     char jname;
     int priority;
     int arrival_time;
     int burst_time;
     int wait_time;
}**jobs;
struct node{
     struct job* jb;
     struct node* prev;
     struct node* next;
}*queueHead,*queueLast;
void insertPriorityQueue(struct node** jnode){
     //struct job* jobb=(*jnode)->jb;
     struct node* temp=queueHead;
     struct node* tjob=*jnode;
     if(queueHead==NULL){
          queueHead=tjob;
          queueLast=tjob;
          return;
     }
     //struct node* prev=temp;
     while(temp!=NULL && (temp->jb->priority)>((*jnode)->jb->priority)){
          temp=temp->next;
     }
     if(temp==NULL){
          queueLast->next=tjob;
          tjob->prev=queueLast;
          queueLast=tjob;
          return;
     }
     if(temp->prev==NULL){
          tjob->next=temp;
          queueHead->prev=tjob;
          queueHead=tjob;
          return;
     }
     tjob->prev=temp->prev;
     tjob->next=temp;
     temp->prev->next=tjob;
     temp->prev=tjob;
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
     printf("jobs sorted aacording to arrival time\nname\tarrival\tpriority\tburst\n");
     for(int i=0;i<n;i++){
          printf("%c\t%d\t%d\t%d\n",jobs[i]->jname,jobs[i]->arrival_time,jobs[i]->priority,jobs[i]->burst_time);
     }
     int timer=jobs[0]->arrival_time;

     printf("Order of execution is..\n");
     printf("JOB\tARRIVAL\tWAIT\tSTART\tEND\tBURST\n");

     for(int i=0;i<n;i++){
          queueHead=(struct node*)malloc(sizeof(struct node));
          queueHead->jb=jobs[i];
          queueHead->next=NULL;
          queueHead->prev=NULL;
          queueLast=queueHead;
          i++;
          //inserted all jobs of same arrival time into the priority queue
          while(queueHead!=NULL && i<n && jobs[i]->arrival_time==queueHead->jb->arrival_time){
               struct node* jt=(struct node*)malloc(sizeof(struct node));
               jt->jb=jobs[i];
               jt->next=NULL;
               jt->prev=NULL;
               insertPriorityQueue(&jt);
               
               i++;
          }
          i--;
          /*display the priority queue
          printf("The queue for arrival time___%d\n",queueHead->jb->arrival_time);
          for(struct node* temp=queueHead;temp!=NULL;temp=temp->next){
               printf("%c__%d\n",temp->jb->jname,temp->jb->priority);
          }
          */  
          
          //now process each job from the queue
          for(struct node* temp=queueHead;temp!=NULL;temp=temp->next){
               temp->jb->wait_time=timer-(temp->jb->arrival_time);
               int start=timer;
               int end=timer+(temp->jb->burst_time);
               timer=end;
               printf("%c\t%d\t%d\t%d\t%d\t%d\n",temp->jb->jname,temp->jb->arrival_time,temp->jb->wait_time,start,end,temp->jb->burst_time);
          }
     }
     return 0;
}