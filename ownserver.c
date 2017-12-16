#include <stdio.h>
#include <ctype.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main()
{
int server_fd, client_fd;

struct sockaddr_in
{
 server_addr;
 client_addr;
};
//socket
server_fd = socket(AF_INET,SOCK_STREAM,0); 


}