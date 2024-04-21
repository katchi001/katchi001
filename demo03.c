#define ALLOCSIZE 10000  // 可用空间大小
static char allocbuf[ALLOCSIZE];  // 分配空间的存储
static char *allocp = allocbuf;  // 下一个空闲位置
char *alloc(int n)  // 返回指向n个字符的指针
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {  // 如果空间足够
        allocp += n;
        return allocp - n;  // 旧位置
    } else  // 空间不足
        return 0;
}
void afree(char *p)  // 释放p指向的存储
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}