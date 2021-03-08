#include <windows.h>
#include <stdio.h>

typedef double (*Func)(double, double);

int main (int argc, char **argv)
{
    Func function;
    double result;

    HINSTANCE hinstLib = LoadLibrary("Math.dll");
    if(hinstLib == NULL){
        printf("ERROR: unable to load DLL\n");
        return 1;
    }
    function = (Func)GetProcAddress(hinstLib, "add");
    if(function == NULL){
        printf("ERROR: unable to find DLL function\n");
        FreeLibrary(hinstLib);
        return 1;
    }

    result = function(1.0, 2.0);
    FreeLibrary(hinstLib);
    printf("Result = %f\n", result);
    return 0;
    system("pause");
}