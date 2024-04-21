#include <ctype.h>  
#include <stdio.h>  

int getch(void);  // 获取一个字符
void ungetch(int);  // 将字符压回输入

int getint(int *pn) {  // 获取整数
    int c, sign;
    while (isspace(c = getch()))  // 跳过空白字符
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {  // 如果不是数字、文件结束符、加号或减号
        ungetch(c);  // 将字符压回输入
        return 0;
    }
    sign = (c == '-') ? -1 : 1;  // 确定符号
    if (c == '+' || c == '-')  // 如果是加号或减号
        c = getch();  // 获取下一个字符
    for (*pn = 0; isdigit(c); c = getch())    //循环直到非数字字符
        { *pn = 10 * *pn + (c - '0');  // 计算整数值
         *pn *= sign; } // 加上符号
    if (c != EOF)  // 如果不是文件结束符
        ungetch(c);  // 将字符压回输入
    return c;  // 返回字符
}