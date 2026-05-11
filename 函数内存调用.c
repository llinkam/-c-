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