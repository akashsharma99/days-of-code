#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char **argv)
{
        int sockfd=socket(AF_INET,SOCK_STREAM,0);
        if(sockfd<0)
                printf("Error is Socket API.\n");
        printf("Socket Created Successfully.\n");
        
        struct sockaddr_in dest;
        dest.sin_port=htons(atoi(argv[1]));
        dest.sin_addr.s_addr=inet_addr(argv[2]);
        dest.sin_family=AF_INET;
  
        char msg[100];
        if(connect(sockfd,(struct sockaddr *)&dest,sizeof(dest))<0)
                printf("Error in Connecting.\n");
        else
                printf("Connection established.\n");
        fd_set stand;
        while(1)
        {
        
        FD_ZERO(&stand);
        FD_SET(0,&stand);
        FD_SET(1,&stand);
        FD_SET(sockfd,&stand);
        
            int flushselect=select(10,&stand,NULL,NULL,NULL);
                bzero(msg,sizeof(msg));
                if(FD_ISSET(0,&stand))
                {
                     int flg=0;
                         int flush=read(0,msg,sizeof(msg)); 
                         if(strcmp(msg,"bye")==0){
                    		printf("Server disconnected!\n");
                    		flg=1;
                    	 }  
                         if(write(sockfd,msg,strlen(msg))<0)
                             printf("Unable to send.\n");
                         else
                             printf("Message Sent.\n");
                          if(flg==1)
                          break;
                         
                }
                if(FD_ISSET(sockfd,&stand))
                {
                    if(recv(sockfd,msg,sizeof(msg),0)<0)
                        printf("Message not received.\n");
                    else
                        printf("Message is:%s\n",msg);
                     
                }
        }
        close(sockfd);
}
