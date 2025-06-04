#include <stdio.h>
/*用于将格式化的字符串输出到一个字符数组中。它有类似于 printf() 的语法和用法，但不是将数据输出到控制台，而是将数据输出到指定的字符数组中。*/ 
//字符串拼接
char str1[] = "Hello";
char str2[] = "world!";
char str3[100];
sprintf(str3, "%s %s", str1, str2);
printf("%s\n", str3); // 输出 "Hello world!"
//数字转字符串
int num = 123;
char str[100];
sprintf(str, "%d", num);
printf("%s\n", str); // 输出 "123"
