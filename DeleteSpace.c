#include <stdio.h>

char *delete_space(char *str)
{
    char *p=&str[0];
    char SpaceNum=0,i=0,q=0;
    // while(*(p+i) !='\0')
    // {
    //     if(*(p+i)==' ')
    //     {   
    //         SpaceNum++;
    //         *(p+i)=*(p+SpaceNum+i);
    //         if(*(p+i)!=' ')
    //             i++;
    //     }
    // }
    while(str[i]!='\0')
    {
        if(str[i]!=' ')
        {   
           str[q++]=str[i];
        }
        i++;
    }
    str[q]='\0';
    return str;
}

void main()
{
    char A1[]="abc  de fghijk l";

    printf("%s\n",A1);
    printf("%s\n",delete_space(A1));
    system("pause"); 
}