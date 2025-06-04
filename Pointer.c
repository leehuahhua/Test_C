#include <stdio.h> 
void Pointer()
{
    //小端存储
    /* Pointer的定义和初始化
    int a=0x4321;
    int *p;//定义一个指向int型数据的指针，表示了从内存首地址开始取几个字节。
    而指针加减法中首地址偏移的单位是由初始化的对象决定，详见ArrayPointer;但一般都是指针类型和对象数据类型是一样的。
    char *p1;
    //p是一个指针变量，指针变量存储的是内存地址(所以系统是多少位它就是多少位的变量)，int 表示这个指针存储的内存地址对应的数据的类型
    p=&a;//取地址。把数据a的首地址赋给p。
    p1=&a;
    //第5行和第8行就完成了指针的定义和初始化，也可以直接 int *p=&a;   
    */
    /*懂了指针定义和初始化的话就直接从这里看*/
    int a=0x4321;
    int *p=&a;
    char *p1=&a;
    void *pi;//任意类型指针，使用时需要强制类型转换
    //void *pi=&a;
    //int b=*(int *)pi
    char **pp=&p;//二级指针存储的是一级指针的地址
    char **pp1=&p+1;
    printf("变量a和p的值                %x    %x\n",a,p);//%x表示16进制输出
    printf("变量a和p所占字节            %d       %d\n",sizeof(a),sizeof(p));
    printf("数据类型不同的指针的取内容  %x    %x\n",*p,*p1);//取内容。*作为单目运算符时表示取内容，将指向的数据拿出来。
    printf("指针++p的运算               %x\n",++p);//p是int型所以++p是向下移4个字节
    printf("一级指针的地址p和p+1的地址  %x  %x\n",pp,pp1);

    system("pause"); 
}
void ArrayPointer()
{
    short a[4]={0x1234,0x5678,0x33,0x44};//数组和指针很像，数组名可以就说是个地址。但是数组是线，指针是点。
    short *p=&a[0]+1;//&a[0]是指向的是一个short型数据的指针，所以+1是加了个2个字节
    char *p1=&a+1; //&a是数组型指针，所以+1是加了一个数组宽度，而这个内存地址未开辟就会出现越界
    char *p11=a+1;//a相当于&a[0]
    /*数组取内容时与指针无异*/
    printf("%x %x %x %x\n",a,a[0],a[1],a[2]);//地址和数据  
    printf("%x %x %x %x\n",(a+1),*a,*(a+1),*(a+2));
    printf("%x %x %x \n",*p,*p1,*p11);
    system("pause"); 
}
//指针常量和常量指针
void const_pointer()
{
    char a[]="a.c";
    char b[]="b.c";

    char *const path=a;//指针常量 
    *path='b';
    printf("%s\n",path);


    const char *path1=b;//常量指针      
    path1="d.c";    //path1指向了“d.c”的首地址
    printf("%s\n",path1);
    system("pause");
}
void main()
{
    //Pointer();
    //ArrayPointer();
    const_pointer();
}
//1.计算机存储数据一般是按字节从小端开始存储的，数据的首地址存储的是数据的第一个字节，首地址也表示这个数据的地址。
//2.指针存的是地址(指针就是地址，地址就是指针,&取地址,*取内容)，指针数据类型表示的是从地址开始取多少个字节
//3.指针的加减运算表示指针向上或下移动多少个数据宽度,小心指针越界到未开辟的内存（野指针）
//4.float的精度传递