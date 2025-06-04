
#include   <stdio.h>
#define text char*//文本替换
typedef char* type;//类型替换
void main()
{
text a,b;//char*a,b
type x,y;//char*a,*b,
printf("%d %d\n",sizeof(a),sizeof(b));
printf("%d %d\n",sizeof(x),sizeof(y));
system("pause");
}