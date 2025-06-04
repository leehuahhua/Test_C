#include   <stdio.h>
main()
{
float a=30.456;
int c=0,d=1,Result,Comma;
if ('\0' == 0) putchar('1');//转义字符'\0'就是0，就如同'\\'表示符号\
if ('0' == 0)  putchar('2');//'0'表示ASCII码中的字符0其值为0x30
if ('a' > 'b') putchar('3');
printf("\n'\x41'\n");//\xhh为 将一到两位16进制数转义成其值对应的ASCII码，在ASCII中41就是A；

Result=c<d?c:d;
printf("%d\n",Result);//“c<d?c:d”是三目条件运算表达式，当？前的的表达式成立则输出a:b的前者不然后者。

Comma=(c=c+6,c/5);
printf("%d\n",Comma);//逗号运算符优先级最低所以一般用括号括起来，可以对多个表达式依次求解，输出值为最后一个表达式的值和类型
printf("%f\n",Comma);

//%5.2f表示输出总宽度为5(包括小数点)，四舍五入取2位小数位数。%e科学计数法

printf("%d,\n%f,%5.2f,%e",(int)a,a,a,a);//%f输出的小数位数占6位
system("pause");
}