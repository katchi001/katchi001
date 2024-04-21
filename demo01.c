#include<stdio.h>
#include<stdlib.h>

#define MAX(x,y) ((x)>(y)?(x):(y))

int main()
{
    int a = 2 ,b = 9 , c ;
    c = MAX(a,b);
    printf("max=%d",c);
    return 0;
}