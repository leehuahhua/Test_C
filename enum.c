#include <stdio.h>
/*存储的是一堆整形常量，长度也和int长度一致*///是
typedef enum      //定义一个枚举类型（相当于一串宏定义），一般用typedef来完成
{
    GPIO_Speed_10MHz=1,//注意是逗号。第一个如未给出取值则默认是从0开始依次加一 当碰到一个赋值过的成员就得从该成员开始依次加一
    GPIO_Speed_4MHz,   //2 
    GPIO_Speed_2MHz,   //3
    GPIO_Speed_5MHz=6,
    GPIO_Speed_7MHz    //7
}GPIO_Speed;//这个枚举类型的名字不是变量，变量和成员是同一级的不同于结构体ex:GPIO_Speed PC1=GPIO_Speed_7MHz;
void main()
{
    int b=6;
    GPIO_Speed PC1=(GPIO_Speed)b;//PC1 是GPIO_Speed的枚举变量所以只能取GPIO_Speed中的枚举成员
    // (GPIO_Speed)b//才能用int型指代enum型//我已忘记为什么我当时写这一段毕竟编译显示无关系//想起来了是有的编译器下不能直接用整形给枚举变量赋值
    printf("%d\n",GPIO_Speed_7MHz);
    printf("%d",PC1);
    system("pause");
}

//用枚举enum来作为数组的索引(没啥用)：就不写了

