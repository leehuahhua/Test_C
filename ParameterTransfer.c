#include <stdio.h>
/*值传递和地址传递*/
//值传递：内存开辟一段空间用来装实参的值，也就是实参和形参用的不是同一地址，形参的值不会影响实参的值。实参是数组就不适合这样做了，效率就太低了。
//地址传递：只需要开辟一个8字节的存储空间(64的系统)来储存实参的地址,用同一地址所以形参会影响实参(可以利用这一点实现一个函数多个返回值),
//但是加前缀const(常量/恒量)就可防止形参对实参的更改

#define CODE_SEL  0//0：FindMax 1：函数指针


#if CODE_SEL==0
int FindMax(const int *Array,int Lenth,int *MaxCount)//用指针Array接住a这个类指针。定义个指向实参MaxCount指针来计Max的个数
{
    int i;
    int Max=Array[0];
    for(i=1;i<Lenth;i++)
    {
        if(Array[i]>Max)
        {
            Max=Array[i];
            *MaxCount=1;
        }
        else if (Array[i]==Max)
        {
            *MaxCount++;
        }     
    }
    return Max;//函数只能return一个值
}
void main()
{
    int Max;
    int MaxCount=1;
    int a[5]={12,45,87,107,2};
    Max=FindMax(a,5,&MaxCount);//第三个参数是指针所以赋值&MaxCount
    printf("Max=%d,MaxCount=%d\n",Max,MaxCount);
    system("pause");
}





#elif CODE_SEL==1
// 指针函数int *b(参数列表);本质是一个函数只是返回值为指针。调用也是直接写函数名();
// 函数指针int (*b)(参数列表);函数指针是指向函数的指针变量。函数指针,用于回调 函数
#include <unistd.h>
void add1(int a)
{
    printf("%d\n",(a+1));
}
void add2(int a)
{
    printf("%d\n",(a+2));
}
//回调函数
void adder(void (*pfunc)(),int a)//一个函数名（函数名是个地址）,定义了一个void型的函数指针pfunc,指向的是一个函数表现为函数名，定义时括号内的参数列表可有可无；
{
    pfunc(a);
}
int main()
{
    int a=2;
    adder(add1,a);//用adder去调用add1函数
    adder(add2,a);//用adder去调用add2函数
    sleep(3);
}
#endif