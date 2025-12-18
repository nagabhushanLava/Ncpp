#include<stdio.h>
int main(void)
{
   // clrscr();

    char *ptr="INDIA";
    printf("the string is %s \n",ptr);

    char str[6]={'I','N','D','I','A','\0'};

    char st1[10] ="INDIA";

    printf("the value od string--->%s\n",st1);
    for(int i=0;i<strlen(str);i++)
    {
        printf("the str is %c \n",str[i]);
    }

    printf("the string is %s\n",str);
    printf("the vaue %c", str[1]);


}