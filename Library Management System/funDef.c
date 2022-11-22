#include <stdio.h>
#define N 100


int stdNum[N], isbnNum[N], num, i, *pISBN=NULL;
char bookTitle[N][N];
/*
 * borrowBook - Store arrays of Student Number, ISBN, Book Title.
 * @num: Number of items to be stored
 */
void borrowBook(int num)
{
    printf("Student Number\n");
    printf("----------------\n");
    for (i = 0; i < num; i++)
    {
        printf("stduent %d: ", i+1);
        scanf("%d", &stdNum[i]);
    }

    printf("ISBN\n");
    printf("----------------\n");
    for (i = 0; i < num; i++)
    {
        printf("ISBN %d: ", i+1);
        scanf("%d", &isbnNum[i]);
    }

    printf("Book Title\n");
    printf("----------------\n");
    for (i = 0; i < num; i++)
    {
        printf("Book Title %d: ", i+1);
        // read & ignore extra characters
        getchar();
        // read string with spaces
        scanf("%[^\n]s", bookTitle[i]);
    }
}

/*
 * viewBooks - View student record of borrowed books.
 * @num: Number of item.
 */
void viewBooks(int num)
{
    for (i = 0; i < num; i++)
    {
        printf("\nStudent %d\n", i+1);
        printf("================\n");
        printf("-  Student Number: %d\n", stdNum[i]);
        printf("-  ISBN: %d\n", isbnNum[i]);
        printf("-  Book Title: %s\n", bookTitle[i]);
    }
}

/*
 * returnBook - Checks if a borrowed book is returned or not.
 * @num: Number of item.
 */
void returnBook(int num)
{
    printf("ISBN: ");
    scanf("%d", pISBN);

    for (i = 0; i < num; i++)
    {
        if (*pISBN == isbnNum[i])
        {
            printf("Return Succesfully");
            /* TODO: Remove student from list if returened */
        }
        else
            printf("Not returned");
    }
}