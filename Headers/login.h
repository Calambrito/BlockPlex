#include <stdio.h>
#include <string.h>
typedef struct
{
    char Password[18];
    char Username[18];
} Profile;

void member(Profile Member, int *discount)
{
    char c;
    puts("\nRoyalPlex members are eligible for a 50 percent discount on their orders.");
    printf("Are you a Royalplex member? (Y/N)\n>");
    while (1)
    {
        fflush(stdin);
        scanf(" %c", &c);
        if (c == 'y' || c == 'Y' || c == 'n' || c == 'N')
            break;
        printf("Invalid Response! Please try again!\n>");
    }
    if (c == 'y' || c == 'Y')
        login(Member, discount);
}
void login(Profile Member, int *discount)
{
    int userIndex, userCount = 5, found, i;
    char checker[18], characterBuffer;
    while (1)
    {
        found = 0;
        fflush(stdin);
        printf("Enter your RoyalPlex Username >");
        gets(Member.Username);
        for (i = 0; i < userCount; i++)
        {
            int j = 0;
            userIndex = i * 40;
            FILE *file = fopen("../Data/Users.txt", "r");
            fseek(file, userIndex, SEEK_SET);
            while ((characterBuffer = fgetc(file)) != '-')
            {
                checker[j] = characterBuffer;
                checker[j + 1] = '\0';
                j++;
            }
            fclose(file);
            j = 0;
            if (!strcmp(checker, Member.Username))
            {
                found = 1;
                break;
            }
        }
        if (found)
            break;
        printf("Incorrect Username Try Again!\n");
    }
    if (verified(Member, i))
        *discount = 2;
}

int verified(Profile Member, int index)
{
    int passwordIndex, userCount = 4;
    char checker[18], characterBuffer;
    while (1)
    {
        fflush(stdin);
        printf("Enter your RoyalPlex Password >");
        gets(Member.Password);

            int j = 0;
            passwordIndex = (index + 1) * 40 - 20;
            FILE *file = fopen("../Data/Users.txt", "r");
            fseek(file, passwordIndex, SEEK_SET);
            while ((characterBuffer = fgetc(file)) != '-')
            {
                checker[j] = characterBuffer;
                checker[j + 1] = '\0';
                j++;
            }
            fclose(file);
            j = 0;
            if (!strcmp(checker, Member.Password))
            {
                printf("Login successful!\nYou will now recieve a 50%% discount on your purchase.\n");
                return 1;
            }
        
        printf("Incorrect Password Try Again!\n");
    }
}