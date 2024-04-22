#include<stdio.h>  
#include<math.h>  
#include<windows.h>

int main()
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); // 获取当前控制台窗口的尺寸
    MoveWindow(console, r.left, r.top, 400, 250, TRUE); // 设置控制台窗口的尺寸为400x250
    SetWindowPos(console, 0, 700, 450, 0, 0, SWP_NOSIZE | SWP_NOZORDER); // 设置控制台窗口在桌面上的位置为 (700, 450)
   

    SetConsoleOutputCP(65001);
    int a, b, j, p, s, k;
    printf("input:\n槽的大小=");
    scanf("%d", &a);
    printf("间隔最小值=");
    scanf("%d", &b);
    printf("间隔最大值=");
    scanf("%d", &p);
    printf("整体长度=");
    scanf("%d", &s);

    for (j = b; j <= p; j++)
    {
        double i = (s - j);
        double o = (a + j);
        double n = i / o;
        k = (int)n;
        double m = n - k;
        if (m < 0.125)
        {
            printf("\n切割槽个数=%d\n\n槽与槽之间的宽度=%d\n\n", k, j);
            break;
        }
    }
    system("pause");
    return 0;
}