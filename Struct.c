/*
    结构体的一般形式：
    struct 结构名(结构名可以不用写，不是变量相当于是对结构的一个注释)//也可以把结构体变量定义在结构名后面eg:struct 结构名 变量{成员表列};
    {
        成员表列
    }变量1,变量2,...;//或者用数组存储这些变量，最下面
    不能将一个结构体变量作为一个整体进行输入和输出，但是同结构的变量可以相互赋值,在定义结构体时才可以对变量逐一地整体赋值
    (错误的eg:printf("%d,%S...\n",student1);
    对变量中成员的引用： 
    "变量名.成员名"其中'.'的是成员运算符(对象)，优先级和括号一样。
    指针变量名->成员名 或者(*指针变量名).成员名

    结构体变量的成员可以像普通变量一样进行各种取决于其类型的各种运算（eg：student1.date.birthday.day是int型就可以进行加法啥的）

*/
extern struct STRUCT_USART_Fram   //数据帧结构体
{
    char Data_RX_BUF[RX_BUF_MAX_LEN];
    union                                         // 联合体，内存长度为成员中最长的内存长度，成员们共用此内存。其定义和初始化和调用和结构体一样                        
    {
        __IO u16 InfAll;                          // 整体访问
        struct                                    // 分位访问                           
        {
            __IO u16 FramLength       :15;        // 14:0 ,“:”是位域操作符，创建了长度为15位的变量。
            __IO u16 FramFinishFlag   :1;         // 15 
        }InfBit;
    }; 
	
}ESP8266_Fram_Record_Struct;


#include <stdio.h>
void main()
{
    struct date
    {
        int year;
        int month;
        int day;
    }birthday;
    struct student
    {
        int num;
        char *name;//也可以用一个数组来代替比如char name[20];指针形式定义的话就是一个字符串常量了只能初始化一次不可更改(别人实践得来的)
        char gender;
        struct  date birthday;//结构体的嵌套,birthday包括年月日就单独写了个结构体，这个结构体的结构名不可以没有不然就不能将两个体进行嵌套
        float score;
    }student1={12,"LEE",'m',2002,8,28,100},student2;//定义时可以对变量进行整体初始化

    printf("结构体变量的内存大小不是简单的成员内存相加(4+8+1+12+4=29)\n%d\t%d\t%d\n",sizeof(student1),sizeof(student2),sizeof(struct student));
    //对student1成员进行赋值，
    student1.num=007;
    student1.name="Lee";
    student1.birthday.day=28;//不是student1.date.birthday.day哦,date不是变量名
    
    //同结构的变量可以相互整体赋值
    student2=student1;
    printf("student1的学号%d 姓名%s 生日%d月%d日\n",student1.num,student1.name,student1.birthday.month,student1.birthday.day);
    printf("student1的学号%d 姓名%s 生日%d月%d日\n",student2.num,student2.name,student2.birthday.month,student2.birthday.day);
    printf("student1的性别是:%c\n",student1.gender);
    system("pause");
}
/*用数组存储结构体变量//结构体数组
    eg:
        struct stu{
            char *name;  //姓名
            int num;  //学号
            int age;  //年龄
            char group;  //所在小组 
            float score;  //成绩
        }class[5] = {
            {"Li ping", 5, 18, 'C', 145.0},
            {"Zhang ping", 4, 19, 'A', 130.5},
            {"He fang", 1, 18, 'A', 148.5},
            {"Cheng ling", 2, 17, 'F', 139.0},
            {"Wang ming", 3, 17, 'B', 144.5}
        };
*/


