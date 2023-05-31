#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void book_tickets(char arr[][3], int *choice)
{
    printf("How many tickets would you like to book > ");
    scanf("%d", choice);
    for (int i = 0; i < *choice; i++)
    {
        printf("Enter index of seat %d: ", i + 1);
        scanf(" %c%c", &arr[i][0], &arr[i][1]);
    }
}
int pay(int choice)
{
    srand(time(0));
    char number[12];
    printf("Your total bill for %d ticket(s) is %d BDT.\nOnline Payments must be paid through NoKash\n\n", choice, choice * 450);
    printf("Enter your NoKash number: ");
    scanf(" %s", number);
    number[11] = '\0';
    int OTP = (rand() % (900000)) + 100000, E_OTP;
    FILE *file;
    file = fopen("../Data/OTP.txt", "w");
    fprintf(file, "%d", OTP);
    fclose(file);
    printf("Please enter the OTP sent to the number %s\n >>", number);
    scanf("%d", &E_OTP);
    if (E_OTP == OTP)
        return 1;
    return 0;
}

void confirm(const char seatindex[][3], const char filepath[], int num)
{
    char final[3] = "NN\0";
    for (int i = 0; i < num; i++)
    {
        final[0] = seatindex[i][0];
        final[1] = seatindex[i][1];
        replace(filepath, final);
    }
}

void replace(const char *filepath, const char *position)
{
    int index = ((int)position[0] - 65) * 38 + 6 * ((int)position[1] - 48);
    if ((int)position[0] < 65 || (int)position[0] > 68 || (int)position[1] < 49 || (int)position[1] > 54)
        invalid_input();
    else
    {
        FILE *file = fopen(filepath, "r+");
        fseek(file, index, SEEK_SET);
        fputc(' ', file);
        fputc('X', file);
        fclose(file);
    }
}