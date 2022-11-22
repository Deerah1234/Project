#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#define N 100


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
        // Option for 1-4
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