#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void print(char *ptr, ...);

int main(void)
{
    print("dfsdx", 1, 2.2, "name", 'a');
    return (0);
}

void print(char *ptr, ...)
{
    int num_args = strlen(ptr);

    va_list argptr;
    va_start(argptr, ptr);

    for (size_t i = 0; i < num_args; i++)
    {
        switch (ptr[i])
        {
            case 'd':
                int integer = va_arg(argptr, int);
                printf("%d ", integer);
                break;
            
            case 'f':
                float floating = va_arg(argptr, double);
                printf("%f ", floating);
                break;
            
            case 's':
                char *string = va_arg(argptr, char*);
                printf("%s ", string);
                break;
            
            case 'c':
                char *character = va_arg(argptr, char*);
                printf("%c ", character);
                break;
            
            case 'x':
                int hexa = va_arg(argptr, int);
                printf("%x ", hexa);
                break;
            
            default:
                break;
        }
    }

    va_end(argptr);
}