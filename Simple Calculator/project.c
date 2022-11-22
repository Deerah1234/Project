#include <stdio.h>

void add(int, int);
void sub(int, int);
void mul(int, int);
void div(int, int);


int main(void)
{
    int choise, num1, num2;
    /*Function pointer array*/
    void (*fptr[])(int, int) = {add, sub, mul, div};

    printf("   Simple Calculator  \n");
    printf("---------------------------\n");
    printf("Choose from 0-3\n");
    printf("-> 0 - Add\n-> 1 - sub\n-> 2 - mul\n-> 3 - div\n");

    while (1)
    {
        printf("Enter your choise\n-> ");
        scanf("%d", &choise);

        if (choise < 0 || choise > 3)
        {
            printf("Invalid choise.\n");
            printf("Please enter a valid choise from 0-3\n");
            continue;
        }
        else
        {
            printf("Enter number 1: ");
            scanf("%d", &num1);
            printf("Enter number 2: ");
            scanf("%d", &num2);

            /* Calling function pointer array */
            fptr[choise](num1, num2);
            return (0);
        }
    }
}

/*
 * add: Add two arguments
 * @a - First argument to add
 * @b - Second argument to add
 */
void add(int a, int b)
{
    printf("Addition of %d+%d = %d", a, b, a+b);
}

/*
 * sub: Subtraction two arguments
 * @a - First argument to add
 * @b - Second argument to add
 */
void sub(int a, int b)
{
    printf("Subtraction of %d-%d = %d", a, b, a-b);
}

/*
 * mul: Multiplication two arguments
 * @a - First argument to add
 * @b - Second argument to add
 */
void mul(int a, int b)
{
    printf("Multiplication of %d*%d = %d", a, b, a*b);
}

/*
 * div: Division two arguments
 * @a - First argument to add
 * @b - Second argument to add
 */
void div(int a, int b)
{
    printf("Division of %d/%d = %f", a, b, (float)a/b);
}