#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
int main(int argc,char* argv[]){
	int selfSocket=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in self;
	self.sin_port=htons(atoi(argv[1]));
	self.sin_addr.s_addr=inet_addr(argv[2]);
	self.sin_family=AF_INET;
	int bindID=bind(selfSocket,(const struct sockaddr*)&self,sizeof(self));
	int listenID=listen(selfSocket,3);
	struct sockaddr_in client;
	int x;
	
	char st[100];
	
	fd_set rfds,copyfds;
	FD_ZERO(&rfds);
	FD_SET(0,&rfds);
	FD_SET(selfSocket,&rfds);
	int sockd=selfSocket;
	int arr[3];
	int top=-1;
while(1){
	copyfds=rfds;
	//printf("Waiting for connection request...\n");
	int sid=select(sockd+1,&copyfds,NULL,NULL,NULL);
	//printf("select worked\n");
	if(sid>0){
		if(FD_ISSET(selfSocket,&copyfds)){
			int acceptID=accept(selfSocket,(struct sockaddr*)&client,&x);
			printf("Connection established: client %d\n",top+1);
			FD_SET(acceptID,&rfds);
			if(top<3){
				arr[++top]=acceptID;
			}
			if(acceptID>sockd){
			sockd=acceptID;
			}
		}
		int i;
		for(i=0;i<=top;i++){
			if(FD_ISSET(arr[i],&copyfds)){
				bzero(st,100);
				int recvID=recv(arr[i],st,sizeof(st),0);
				printf("Message received: %s\n",st);
				if(strcmp(st,"bye")==0){
					
					close(arr[i]);
					FD_CLR(arr[i],&rfds);
					for(int j=i;j<top;j++){
						arr[j]=arr[j+1];
					}
					top--;
				}
			}
		}
		bzero(st,100);
                if(FD_ISSET(0,&copyfds))
                {
                     
                         int flush=read(0,st,sizeof(st));
                         printf("enter client no to send to %d:",top);
			 int x;
			 scanf("%d",&x);   
			 if(x<=top)
			 	send(arr[x],st,strlen(st),0);              
                         /*if(write(arr[x],st,strlen(st))<0)
                             printf("Unable to send.\n");
                         else
                             printf("Message Sent.\n");*/
                         
                }
		
	}
	
	
}
	close(selfSocket);
	return 0;	
	
}
