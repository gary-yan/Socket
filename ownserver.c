#include <stdio.h>
#include <ctype.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define PORT 9001
#define MAX_QUEUE 5
int main()
{
int server_fd;
int client_fd;

struct sockaddr_in server_addr;
struct sockaddr_in client_addr;//专门用来存储网络地址
socklen_t client_addr_len = sizeof(client_addr);//

//{
 //server_addr;
 //client_addr;
//};
//socket
server_fd = socket(AF_INET,SOCK_STREAM,0); 
//报错
if (server_fd < 0)
{
	perror("socket");
	exit(-1);
	/* code */
}
//设置端口 IP 和TCP／IP协议族
server_addr.sin_family = AF_INET; //协议族
server_addr.sin_port = htons(PORT);
server_addr.sin_addr.s_addr = htonl(INADDR_ANY);//

//bind
if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr))<0)
{
	perror("bind");
	exit(-1);/* code */
}

//listen
if (listen(server_fd, MAX_QUEUE) < 0)
{
	perror("listen");/* code */
	exit(-1);
}
printf("the server running on port %d\n", PORT);
printf("MAX QUEUE = %d\n" , MAX_QUEUE);

//accept
for( ; ;){
client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
if (client_fd < 0)
{
	perror("accept");
	exit(-1);
	/* code */
}
printf("accept a client\n");
printf("client socket file descriptor: %d\n", client_fd );
}





}