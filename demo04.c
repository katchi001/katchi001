#include <stdio.h>
#include <stdlib.h>


void my_strcpy(char *s, char *t)
 {
 while (*s++ = *t++)
 ;
 }



int main()
{
    char  my[]= "12345";
    char you[7];
    my_strcpy(you,my);
    printf("%s",my);
    return 0;
}


