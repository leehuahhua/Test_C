
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int id;                 //学生id
    char name[30];          //学生姓名
    char address[100];      //学生地址
}Student;
//typedef struct
void main()
{
    Student student;//student 就被定义成Student这个结构体的变量了
    FILE* fp = fopen("D:\\VS code\\C\\test\\2.txt", "wt+");

    printf("请依次输入学生的id,姓名和地址:\n");
    scanf("%d%s%s", &student.id, student.name, student.address);
 
    //将学生信息存入D:\\VS code\\C\\test\\2.txt文件中
    fprintf(fp, "%d\t%s\t%s\n", student.id, student.name, student.address);
 
    Student temp;
    //重置文件指针
    rewind(fp);
    //将文件中的信息读取出来并且存储到temp中
    fscanf(fp, "%d\t%s\t%s\n", &temp.id, temp.name, temp.address);
 
    printf("第%d位学生的姓名为:%s,地址为%s\n", temp.id, temp.name, temp.address);
    
    fclose(fp);
    system("pause");
}