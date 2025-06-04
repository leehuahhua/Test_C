/*===============================================================
*   Copyright (C) 2024 All rights reserved.
*   
*   文件名称：TCP.c
*   创 建 者：Lee
*   创建日期：2024年05月23日
*   描    述：
*
*   更新日志：
*
================================================================*/
#include <stdio.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <netinet/ip.h>

int main()
{
	//TCP
	#define port 8888 
	#define IPV4 192.168.10.81
	
	//socket
	int sfd=socket(AF_INET,SOCK_STREAM,0);//return socket
	if(sfd<0)
	{
		perror("socket");
		return -1;
	}
	printf("socket success!\n");

	//bind
	struct sockaddr_in ser;
	ser.sin_family=AF_INET;
	ser.sin_port=htons(port);		
	ser.sin_addr.s_addr=inet_addr("IPV4");
	/*端口转换函数：
	/short htons(short num);		//把主机字节序转换成网络字节序 host to network short*/
	/*IP转换函数：
	/inet_addr(char *str);		//把点分形式的IP字符串转换成网络字节序的二进制IP*/


	
	int ret=bind(sfd,(struct sockaddr *)&ser, sizeof(ser));
	if(ret<0)
	{
		perror("bind");
		return -1;
	}
	printf("bind success!\n");

	//listen
	ret=listen(sfd,10);//arg 2是在进入队列中等待被处理的连接的最大数量,新的连接请求将被拒绝
	if(ret<0)
	{
		perror("listen\n");
		return -1;
	}
	
	//accept
	struct sockaddr_in client_addr;
	.
	int Client_Addrlenth=sizeof(client_addr);
	ret=accept(sfd,(struct sockaddr *)&client_addr,&Client_Addrlenth);
	if(ret<0)
	{
		perror("accept\n");
		return -1;
	}	
	printf("welcome!\n");

}
