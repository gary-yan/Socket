#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERV_PORT  8000
int main(void)
{

	int lfd, cfd;
	struct sockaddr_in serv_addr, clin_addr;
	socklen_t clin_len;
	char buf[1024]; 
	int len;
	//结构组变量serv_addr 用来存储 IP和PORT
	//AF_INET : IPV4   SOCK_STREAM : stream 协议  0:tcp
	lfd = socket(AF_INET, SOCK_STREAM, 0);

	//IP + PORT
	serv_addr.sin_family = AF_INET;  //表示TCP/IP协议 ipv4 // sin_family协议簇 
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // 构造地址。 表示绑定的地址为本地地址 htonl = host to net long 
	//INADDR_ANY 本机的任意一个一个地址 任意一个网卡都可以接收
	//sin_addr是一个联合体 用联合体可以用多种形式表达IP地址
	serv_addr.sin_port = htons(SERV_PORT);  //host to net short  网络序－－大端存储
	bind(lfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)); //(struct sockaddr *)&serv_addr强制类型转换   泛型指针 void＊

	listen(lfd,128);

	clin_len = sizeof(clin_addr);
	cfd = accept(lfd, (struct sockaddr *)&clin_addr, &clin_len);
	len = read(cfd, buf, sizeof(buf)); //读取存到缓存中 buf buffer
	write(STDOUT_FILENO, buf, len );//标准输出 打印到屏幕上
	close(lfd);
	close(cfd);
	return 0;

}