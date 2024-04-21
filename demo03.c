#include <stdio.h>  // 包含标准输入输出头文件
#include <stdlib.h>  // 包含标准库头文件
#include <ctype.h>  // 包含字符处理头文件

#define MAXSTACK 100  // 定义最大栈容量为100

int stack[MAXSTACK];  // 定义整型数组作为栈
int stackpos = 0;  // 初始化栈顶位置为0

void push(int value) {  // 定义入栈函数
    if (stackpos < MAXSTACK) {  // 如果栈未满
        stack[stackpos++] = value;  // 将值入栈
    } else {  // 否则
        printf("error: stack full\n");  // 打印栈满错误信息
    }
}

int pop() {  // 定义出栈函数
    if (stackpos > 0) {  // 如果栈非空
        return stack[--stackpos];  // 返回栈顶元素并将栈顶位置减一
    } else {  // 否则
        printf("error: stack empty\n");  // 打印栈空错误信息
        return 0;  // 返回0
    }
}

int main(int argc, char *argv[]) {  // 主函数
    int i, op1, op2;  // 定义变量
    for (i = 1; i < argc; i++) {  // 遍历命令行参数
        if (isdigit(*argv[i])) {  // 如果是操作数
            push(atoi(argv[i]));  // 将操作数入栈
        } else {  // 否则是运算符
            switch (*argv[i]) {  // 根据运算符进行相应操作
                case '+':  // 加法
                    push(pop() + pop());  // 将栈顶两个元素相加并将结果入栈
                    break;
                case '-':  // 减法
                    op2 = pop();  // 出栈得到第二个操作数
                    op1 = pop();  // 出栈得到第一个操作数
                    push(op1 - op2);  // 将两个操作数相减的结果入栈
                    break;
                case 'x':  // 乘法
                    push(pop() * pop());  // 将栈顶两个元素相乘并将结果入栈
                    break;
                case '/':  // 除法
                    op2 = pop();  // 出栈得到除数
                    op1 = pop();  // 出栈得到被除数
                    if (op2 != 0) {  // 如果除数不为0
                        push(op1 / op2);  // 将两个操作数相除的结果入栈
                    } else {  // 否则
                        printf("error: zero divisor\n");  // 打印除数为0错误信息
                    }
                    break;
                default:  // 其他情况
                    printf("error: unknown operator\n");  // 打印未知运算符错误信息
                    return -1;  // 返回-1
            }
        }
    }
    printf("%d\n", pop());  // 打印栈顶元素作为计算结果
    return 0;  // 返回0
}