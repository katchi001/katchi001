#include <stdio.h>  // 包含标准输入输出头文件
#include <string.h>  // 包含字符串处理头文件
#define MAXLINES 5000  // 最大可排序行数
char *lineptr[MAXLINES];  // 指向文本行的指针数组
int readlines(char *lineptr[], int nlines);  // 读取输入行
void writelines(char *lineptr[], int nlines);  // 输出文本行
void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));  // 排序输入行
int numcmp(char *, char *);  // 比较数字字符串

/* 对输入行进行排序 */
main(int argc, char *argv[]) {
    int nlines;  // 读取的输入行数
    int numeric = 0;  // 如果是数字排序则为1
    if (argc > 1 && strcmp(argv[1], "-n") == 0)  // 如果命令行参数中包含"-n"
        numeric = 1;  // 设置为数字排序
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {  // 如果读取输入行成功
        qsort((void**) lineptr, 0, nlines-1, (int (*)(void*,void*))(numeric ? numcmp : strcmp));  // 对输入行进行排序
        writelines(lineptr, nlines);  // 输出排序后的文本行
        return 0;  // 返回0
    } else {  // 否则
        printf("input too big to sort\n");  // 打印输入行过多无法排序的信息
        return 1;  // 返回1
    }
}