#include <stdlib.h>
#include <stdio.h>
void my_init(void) __attribute__((constructor));
void mu_init(void)
{
    printf("Hello");
}

int main()
{
    printf("World!\n");
    system("pause");
    return 0;
}