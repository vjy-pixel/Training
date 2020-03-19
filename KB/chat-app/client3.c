#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<stdatomic.h>
#include <sys/wait.h>

#define BUFLEN 1024
#define PORT 8081


void err(char *s)  
{  
perror(s);  
exit(1);  
}  
sig_atomic_t child_exit_status;

void clean_up_child_process (int signal_number) 
{
/* Clean up the child process. */ 
int status; 
wait (&status); 
/* Store its exit status in a global variable. */ 
child_exit_status = status;
}

 int main(int argc, char** argv)  
 {  
 struct sockaddr_in serv_addr;  
 int sockfd, slen=sizeof(serv_addr);  
 char buf[BUFLEN];  
 struct sigaction sigchld_action; 
 memset (&sigchld_action, 0, sizeof (sigchld_action)); 
 sigchld_action.sa_handler = &clean_up_child_process; 
 sigaction (SIGCHLD, &sigchld_action, NULL);
 int pid,ppid;


 printf("argc:%d\n",argc);
 if(argc != 2)  
 {  
   printf("Usagea : %s <Server-IP>\n",argv[0]);  
   exit(0);  
 }  

 if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)  
     err("socket");  

 bzero(&serv_addr, sizeof(serv_addr));  
 serv_addr.sin_family = AF_INET;  
 serv_addr.sin_port = htons(PORT);  
 if (inet_aton(argv[1], &serv_addr.sin_addr)==0)  
 {  
     fprintf(stderr, "inet_aton() failed\n");  
     exit(1);  
 }
 pid = fork();
 if (pid<0) {
     err("Fork Error");
 }else if (pid==0) {
     //child process will receive from server
     while (1) {
         bzero(buf,BUFLEN);
         //printf("Attempting to READ to socket %d: ",sockfd);
         fflush(stdout);
         //recvfrom here
         if (recvfrom(sockfd, buf, BUFLEN, 0, (struct sockaddr*)&serv_addr, &slen)==-1)  
             err("recvfrom()");

         printf("The message from the server is: %s \n",buf);
         if (strcmp(buf,"bye\n") == 0) {
             ppid = getppid();
             kill(ppid, SIGUSR2);

             break;
         }
     }
 }else {
     //parent will send to server
     while(1){
         printf("Please enter the message to send: ");
         bzero(buf,BUFLEN);
         fgets(buf,BUFLEN,stdin);
         printf("Attempting to write to socket %d: ",sockfd);
        // fflush(stdout);
         //send to here
         if (sendto(sockfd, buf, BUFLEN, 0, (struct sockaddr*)&serv_addr, slen)==-1)
         {
             err("sendto()");
         }
     }
 }
 close(sockfd);  
 return 0;  
}