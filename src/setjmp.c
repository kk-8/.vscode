#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
jmp_buf b;
void f()
{
    longjmp(b, 1);
}
int main()
{
    if (setjmp(b))
        printf("World!");
    else
    {
        printf("Hello");
        f();
    }
    system("pause");
}