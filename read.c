//李read();
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
//#include <sys/types.h>
//#include <sys/stat.h>
#include <string.h>
int main()
{
    int fd=open("FuncP.c",O_RDONLY);
    if(fd<0)
    {
        perror("open");
        return -1;
    }
    else
        {
            printf("open success\n");
            char buf[23]={0};
            while(1)
            {
                memset(buf,0,sizeof(buf));
                int ret=read(fd,buf,sizeof(buf));
                if(ret<0)
                {
                    perror("read");
                    return -1;
                }
                if(ret==0)
                break;
                printf("%s",buf);
            }
        }
    return 0;
}