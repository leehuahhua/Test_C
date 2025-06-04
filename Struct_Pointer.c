#include <stdio.h>
void concept()//结构体指针的一个概念
{
    struct stu
    {
    char *name;  //姓名
    int num;  //学号
    int age;  //年龄
    char group;  //所在小组
    float score;  //成绩
    } stu1 = { "Tom", 12, 18, 'A', 136.5 }, *pstu = &stu1;//pstu是一个指向结构体变量stu1地址的指针(结构体指针)
    //读取结构体成员的值(可以用<(*指针).成员名>也可以用 <指针->成员名>)
    printf("%s的学号是%d,年龄是%d,在%c组,今年的成绩是%.1f!\n", (*pstu).name, (*pstu).num, (*pstu).age, (*pstu).group, (*pstu).score);
    printf("%s的学号是%d,年龄是%d,在%c组,今年的成绩是%.1f!\n", pstu->name, pstu->num, pstu->age, pstu->group, pstu->score);
}

void application()//结构体指针的一个应用
{
    struct stu
    {
        char *name;  //姓名
        int num;  //学号
        int age;  //年龄
        char group;  //所在小组
        float score;  //成绩
    }stus[]={
                {"Zhou ping", 5, 18, 'C', 145.0},
                {"Zhang ping", 4, 19, 'A', 130.5},
                {"Liu fang", 1, 18, 'A', 148.5},
                {"Cheng ling", 2, 17, 'F', 139.0},
                {"Wang ming", 3, 17, 'B', 144.5}
            }, *ps;
 
    //求数组长度
    int len = sizeof(stus) / sizeof(struct stu);//可以直接看出来数组变量元素有5个
    printf("%d\n",len);
    printf("Name\t\tNum\tAge\tGroup\tScore\t\n");
    for(ps=stus; ps<stus+len; ps++)//打印每个数组元素
    {
        printf("%s\t%d\t%d\t%c\t%.1f\n", ps->name, ps->num, ps->age, ps->group, ps->score);
    }
}
void main()
{
    //concept();
    application();
    system("pause");
}


