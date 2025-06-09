/*一个简单的链表：*/
#include <stdio.h>
struct node
{
    int data;
    struct node*next;//这个地方存的是结构体指针变量，通过它链接下个变量ex：a.next=&b;结构变量a的指针指向b。
};


typedef struct node NODETYPE;//typedef (struct node{}) NODETYPE;
/*
typedef struct node
{
    int data;
    struct node*next;//这个地方存的是结构体指针变量，通过它链接下个变量ex：a.next=&b;结构变量a的指针指向b。
}NODETYPE;
*/





void main()
{
    NODETYPE a,b,c,*h,*p;
    a.data=10;b.data=20;c.data=30;//给变量中data域赋值
    h=&a;//将结点相连
    a.next=&b;b.next=&c;c.next=NULL;
    p=h;
    while(p)//移动p,使之依次指向a、b、c,输出它们data域中值
    {
        printf("%d ",p->data);
        p=p->next;//p顺序后移
    }
    printf("\n");
    system("pause");
}
