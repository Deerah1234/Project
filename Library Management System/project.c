#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100

/* Prototypes */
void borrowBook(int);
void viewBooks(int);
void returnBook(int);

/* Global Variables */
int stdNum[N], isbnNum[N], num, i, *pISBN=NULL;
char bookTitle[N][N];

int main(void)
{
    char defaultPsswrd[] = "Admin123";
    int loginAttempt = 0, option;
    char password[N], answr[N];
    
    /* Clear ouput screen */
    system("clear");

    jump:
    while (loginAttempt < 3)
    {
        printf("Password: ");
        scanf("%s", password);

        if (strcmp(password, defaultPsswrd) == 0)
        {
            printf("\n******************************\n");
            printf("DKUT Library Management System\n");
            printf("******************************\n");
            printf("1. Borrow a Book\n");
            printf("2. View borrowed books\n");
            printf("3. Return a Book\n");
            printf("4. Quit\n");
            break;
        }
        else
            loginAttempt++;
    }

    if (loginAttempt == 3)
    {
        system("clear"); // Clear screen
        printf("You have exhausted your number of login");
    }
    else
    {
        // Choose from 1-4
        scanf("%d", &option);
        system("clear"); // Clear screen
            switch (option)
        {
        case 1:
            printf("How many student?\n->: ");
            scanf("%d", &num);
            borrowBook(num);
            printf("Do you want to issue another book?: ");
            scanf("%s", answr);
            system("clear"); // clear screen
            if (strcmp(answr, "y") == 0 | strcmp(answr, "Y") == 0)
                goto jump;
            break;

        case 2:
            viewBooks(num);
            break;

        case 3:
            returnBook(num);
            break;
        
        case 4:
            break;
        }
    }
    return (0);
}

/*
 * borrowBook - Store arrays of Student Number, ISBN, Book Title.
 * @num: Number of items to be stored.
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
        scanf("%[^\n]s", &bookTitle[i]);
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
            printf("Return Succesfully");
        else
            printf("Not returned");
    }
}