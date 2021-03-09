#include <stdio.h>
#include <stdlib.h>
void my_init(void)
{
    printf("Hello");
}
typedef void (*ctor_t)(void);
//在。ctors段里添加一个函数指针
ctor_t __attribute__((section(".ctors"))) my_init_p = &my_init;

int main()
{
    printf("World!\n");
    system("pause");
    return 0;
}