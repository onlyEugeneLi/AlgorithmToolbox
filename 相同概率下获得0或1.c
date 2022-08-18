// 笔记转载于https://www.techiedelight.com/zh/get-0-1-equal-probability-using-specified-function/
// 方法一：编写一个算法，使用一个以相等概率生成从 1 到 5 的随机数的函数以相等的概率获得 0 和 1。
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
// 以等概率生成 1 到 5 的随机数的函数
int random() {
    return (rand() % 5) + 1;
}
 
// 使用 `random()` 函数以相等的概率返回 0 或 1
int generate()
{
    int r;
 
    do {
        // `r` 可以是 1、2、3、4 和 5 中的任何一个
        r = random();
    } while (r == 5);
 
    // `r` 现在可以是 1、2、3、4 中的任何一个
 
    // 因为有 2 个奇数和 2 个偶数，返回 `r` 的最后一位，
    // 可能是 0 或 1 的概率相等
    return r & 1;
}
 
int main(void)
{
    srand(time(NULL));
 
    int x = 0, y = 0;
 
    // 对 `generate()` 进行 10000 次调用
    for (int i = 1; i <= 10000; i++) {
        generate()? x++: y++;
    }
 
    // 打印结果
    printf("0 ~ %0.2f%\n", x/100.0);
    printf("1 ~ %0.2f%\n", y/100.0);
 
    return 0;
}

// 结果：
// 0 ~ 50.23%
// 1 ~ 49.77%

// 方法二：也可以增加random()功能
int generate()
{
    int r;
 
    do {
        // `r` 可以是 1、2、3、4 和 5 中的任何一个
        r = random();
    } while (r > 2);
 
    // `r` 现在可能是 1 或 2
 
    return r - 1;
}
