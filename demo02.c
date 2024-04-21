#include <stdio.h> // 包含标准输入输出库的头文件
#define MAXLINE 1000 // 定义最大行长度为1000

int getline(char line[], int maxline); // 函数声明，用于读取输入行
int remove_trailing_blanks(char line[], int len); // 函数声明，用于删除行末空格和制表符

int main() { // 主函数
    int len; // 定义长度变量
    char line[MAXLINE]; // 定义字符数组，用于存储每一行的内容

    while ((len = getline(line, MAXLINE)) > 0) { // 循环读取每一行，直到没有更多的行
        len = remove_trailing_blanks(line, len); // 调用函数删除行末空格和制表符
        if (len > 0) { // 如果删除后的行长度大于0
            printf("%s", line); // 打印该行
        }
    }

    return 0; // 主函数返回0，表示程序正常结束
}

int getline(char s[], int lim) { // 读取输入行并返回其长度的函数
    int c, i; // 定义字符变量和索引变量

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) { // 循环读取字符，直到达到最大长度、读到文件结束符或读到换行符
        s[i] = c; // 将读取的字符存入数组
    }

    if (c == '\n') { // 如果读到的是换行符
        s[i] = c; // 存入数组
        ++i; // 增加索引
    }

    s[i] = '\0'; // 在字符串末尾添加空字符，表示字符串结束
    return i; // 返回行的长度
}

int remove_trailing_blanks(char s[], int len) { // 删除行末空格和制表符的函数
    int i = len - 1; // 初始化索引为行长度减1

    while (i >= 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')) { // 从行末开始，循环删除空格和制表符
        --i; // 减小索引
    }

    s[i + 1] = '\n'; // 在删除后的行末添加换行符
    s[i + 2] = '\0'; // 在字符串末尾添加空字符，表示字符串结束
    return i + 1; // 返回删除后的行长度
}
