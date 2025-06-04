#include <stdio.h> 
//""自带\0所以printf时可以字符串形式打印
void String()/*定义一个字符串数组*/
    {
         /*直接定义*/
        char Str[]="abffj";// char Str[]={"abffj"};只有一个字符串时可以这样定义
        /*数组储存定义*/
        char Str1[]={'a','b','f','f','j','\0'};/*字符串就是一个以'\0'为结尾的字符数组*/
        char Str2[]={'a','b','f','f','j'};//无结束标志\0会乱输出

        
        /*指针*/
        char *Str3="abcde";
        //这样定义的abcde是个常量，不能对其修改(例如：*Str=1;)，可以选择对Str重新给一个地址(例如：Str3=“a2”;)但是仍然为常量后续不可对常量更改
        //或&一个变量的地址(例如：Str3=(char[]){"b3"}; )就可以后续对内容进行更改
        // Str3=“a2”;是将常量“a2”的首地址给到了Str3，不是对原Str3的内容进行更改

        printf("%s\n%s\n%s\n%s\n",Str,Str1,Str2,Str3);

    }

void Stack_Printf()/*C函数参数处理顺序*/ //看个乐呵，反正工作中不会遇到
    {
        int a=1,b=2,c=3;
        printf("%d,%d\n",a,++a);//C函数参数是从最右端开始处理
        printf("%d\n",a);

        // printf("%d\n%d\n%d\n%d\n",a=b=c,a=b==c,a==(b=c),a==(b==c));
        // printf("%d\n",a==(b==c));
        // printf("%d %d %d\n",a,b,c);
        // printf("%d\n",a==(b=c));
        // printf("%d %d %d\n",a,b,c);
        // printf("%d\n",a=b==c);
        // printf("%d %d %d\n",a,b,c);
        // printf("%d\n",a=b=c);
        // printf("%d %d %d\n",a,b,c);
    }

void String_Array()/*指针型数组*/
{
    char *Str[]={"hello","world"};//根据运算符优先级，[]先于*所以是个数组//字符串数组
    printf("%s,%s\n",Str[0],Str[1]);
    char Str1[][5]={"fuck","world"};//二维数组
    printf("%s,%s\n",Str1[0],Str1[1]);
    printf("%c,%c\n",Str1[0][2],Str1[1][1]);
}
 
void main()
{
    String_Array();
    //String();
    // Stack_Printf();
    system("pause");
  
}