#include <stdio.h>
#include <stdlib.h>
void File_input() /*读写模式下输入内容到文件*/
    {
        FILE *fp;//定义一个文件型指针变量
        char ch,filename[20];
        // FILE f[5];//定义一个可以存5个文件型元素的数组
        printf("please input a filename you wanna write:\n");
        scanf("%s",filename);//filename是个数组首地址就不需要再取地址了
        fp=fopen(filename,"w+");//fopen返回值是一个地址所以用fp来接
        printf("please input the sentence you wanna write:\n");
        ch=getchar();//用于吸收（清理掉）上个scanf读取字符后留下的回车。getchar()可以读取空格回车
        //scanf输入后遇到空格和回车就会停止读取且不会去处理它就留在了缓存区，scanf输入前碰到空格或回车会自动丢弃缓存区的空格或回车所以对连续的下个scanf无影响。
        ch=getchar();//输入一串字符时只接受了一个字符的输入其余字符在缓存区通过下面循环实现输出一串字符
        while(ch!=EOF)//fputc写入成功返回写入的字符，写入失败(或者end of file)则返回EOF（-1）。但是这里EOF不是fputc返回的而是输入字符输入的ctrl+z不合规字符导致fputc停止顺便跳出输入字符ch。
        {
            fputc(ch,fp);//写入ch
            ch=getchar(); 
        }
        fclose(fp);
    }
void File_output()/*只读出文件中的内容*/
    {
        FILE *fp;//定义一个文件型指针变量
        char ch,filename[20];
        printf("please input a filename you wanna read:\n");
        scanf("%s",filename);//filename是个数组首地址就不需要再取地址了
        fp=fopen(filename,"r");
        while(ch!=EOF)//ctrl+z
        {
            ch=fgetc(fp);//读出字符存入ch
            putchar(ch); 
        }
        fclose(fp);system("pause");
    }
void main()
{
    // File_input();
    File_output();
}

// #include <stido.h>
// #include <unistd.h>
// int main()
// {
//     int fd=open("FuncP.c",O_RDONLY);
//     if(fd<0)
//     {
//         perror("open");
//         return -1;
//     }
//     else
//         {
//             pritnf("open success\n");
//             char buf[64]={0};
//             while(1)
//             {
//                 memset(buf,0,sizeof(buf));
//                 int ret=read(fd,buf,sizeof(buf));
//                 if(ret<0)
//                 {
//                     perro("read");
//                     retun -1;
//                 }
//                 if(ret==0)
//                 break;
//                 printf("%s",buf);
//             }
//         }
// }