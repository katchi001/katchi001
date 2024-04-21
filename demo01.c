#include <stdio.h> // 引入标准输入输出库
#define MAXLINE 1000 // 定义最大行长度为1000

// 函数声明
int getline(char line[], int maxline);

// 主函数
int main() {
    int len; // 定义长度变量
    char line[MAXLINE]; // 定义字符数组，用于存储每一行的内容

    // 循环读取每一行，直到没有更多的行
    while ((len = getline(line, MAXLINE)) > 0) {
        // 如果行的长度大于8，打印该行
        if (len > 8) {
            printf("%s", line);
        }
    }

    return 0; // 主函数返回0，表示程序正常结束
}

// getline函数，读取一行并返回其长度
int getline(char s[], int lim) {
    int c, i; // 定义字符变量和索引变量

    // 循环读取字符，直到达到最大长度、读到文件结束符或读到换行符
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c; // 将读取的字符存入数组
    }

    // 如果读到的是换行符，也存入数组
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0'; // 在字符串末尾添加空字符，表示字符串结束
    return i; // 返回行的长度
}
