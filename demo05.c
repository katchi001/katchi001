#include <stdio.h>



void my_strcat(char *s, char *t) {
    while (*s) {  // 找到s指向的字符串的末尾
        s++;
    }
    while (*t) {  // 逐个将t指向的字符串中的字符复制到s指向的字符串的末尾
        *s = *t;
        s++;
        t++;
    }
    *s = '\0';  // 在新的末尾加上字符串结束符\0
}





void strend(char *s ,char *t)
{
    while(*s)
    {
        s++;
        while(*t)
        {
            t++;
        }
    }
    while(*t)
    {
        if(*t=*s)
        {
            t--;
            s--;
            return 1;
        }
        else
        {
            return 0;
        }
    }

}

