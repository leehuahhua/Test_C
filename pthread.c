/*===============================================
*   文件名称：pthread.c
*   创 建 者：     
*   创建日期：2024年05月23日
*   描    述：
================================================*/
#include <stdio.h>
#include <pthread.h>//pthread_create() ... && gcc xxx.c -lpthread编译链接库
#include <unistd.h>//sleep()

#define CodeSel 0//0：线程回收(主线程阻塞等待释放) 1：线程分离

void *DoSomethingElse(void *arg)//子线程
{
    while(1)
    {
    	int b;
		printf("son!\n");
		sleep(1);	
		printf("son_arg=%d\n",*(int *)arg);
		#if CodeSel==0 //线程回收
			scanf("%d",&b);//输入为0主动结束子线程
			if(b==0)
			{
				pthread_exit("out!");
				//break;
			}
		#endif
	}
}
int main()//主线程
{
	int a=1;
    pthread_t thread1;//线程1
    int ret=pthread_create(&thread1,NULL,DoSomethingElse,&a);//线程创建并返回值//第四个参数是传递给DoSomethingElse的形参
    if(ret != 0)//判断是否成功创建
    {
		perror("pthread");
		return -1;
    }
    #if CodeSel==1 //线程分离
		pthread_detach(thread1);//线程分离应在线程创立完成马上分离,此后子线程由系统管理
		printf("son has been separated from his dad\n");
    
    #elif CodeSel==0//线程回收
		void *retval;//接子线程释放传递的信息
		ret=pthread_join(thread1, &retval);
    	if(ret != 0)//判断是否成功回收线程
   		{
			perror("pthread_join");
			return -1;
    	}
		printf("My son said, \n%s\n", (char *)retval);
    #endif
    while(1)
    {
        scanf("%d",&a);
        sleep(1);
        printf("=%d\n",a);
    }
}