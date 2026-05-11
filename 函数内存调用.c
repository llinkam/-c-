/**
 * @file    函数内存调用.c
 * @brief   函数指针基础示例：通过指针间接调用硬件操作函数
 *
 * 本示例演示如何将 led() 和 LCD() 两个硬件操作函数的地址
 * 赋值给函数指针变量，并通过指针完成间接调用。
 *
 * 核心思想：
 *   函数编译后在内存中拥有固定地址，函数指针存储该地址，
 *   从而实现运行时动态绑定——上层逻辑无需关心底层具体实现，
 *   只需持有指针句柄即可完成调用。
 *
 * 典型应用场景：
 *   - 驱动层回调注册（UART/SPI/ADC 中断完成回调）
 *   - 事件分发表（替代多分支 if-else）
 *   - HAL 抽象层（不同硬件平台共用同一套上层逻辑）
 *
 * @author  Lin
 * @date    2026-05-11
 */
#include <stdio.h>
void led(void)
{

}
void LCD(void)
{

}
typedef void (*Handler_t)(void);
Handler_t ft = led;
Handler_t ft2 = LCD;
int main(void)
{
    printf("ft 地址: %p\n", (void*)ft);
    printf("ft2 地址: %p\n", (void*)ft2);
    ft();
    ft2();
}
