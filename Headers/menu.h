#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void book_tickets(char arr[][3], int *choice, char fpath[])
{
    char temparr[3];
    int SumArray[48], tempc;
    while (1)
    {
        fflush(stdin);
        printf("How many tickets would you like to book > ");
        scanf("%d", choice);
        printf("\n");
        if (*choice >= 1 && *choice <= 24)
            break;
        printf("Invalid Choice, Please Try Again.\n");
    }
    for (int i = 0; i < *choice; i++)
    {
        while (1)
        {
            int repeated = 0;
            printf("Enter index of seat %d: ", i + 1);
            scanf(" %c%c", &arr[i][0], &arr[i][1]);
            temparr[0] = arr[i][0];
            temparr[1] = arr[i][1];
            if ((int)arr[i][0] < 65 || (int)arr[i][0] > 68 || (int)arr[i][1] < 49 || (int)arr[i][1] > 54)
            {
                printf("That index does not exist, please try again.\n");
                continue;
            }
            else
            {
                if (istaken(fpath, temparr))
                {
                    printf("That seat is taken please try again.\n");
                    continue;
                }
            }
            SumArray[2 * i] = (int)arr[i][0];
            SumArray[2 * i + 1] = (int)arr[i][1];
            for (int j = 0; j < i; j++)
            {
                if (SumArray[2 * i] == SumArray[2 * j] && SumArray[2 * i + 1] == SumArray[2 * j + 1])
                {
                    printf("You have already selected this seat.\n");
                    repeated = 1;
                    break;
                }
            }
            if (repeated)
                continue;
            break;
        }
    }
}
int pay(int choice, int discount)
{
    srand(time(NULL));
    char number[12];
    printf("\nYour total bill for %d ticket(s) is %d BDT.\nOnline Payments must be paid through NoKash\n\n", choice, (choice * 400 / discount));
    printf("Enter your NoKash number: ");
    scanf(" %s", number);
    number[11] = '\0';
    while (1)
    {
        int OTP = 0, E_OTP;
        for (int i = 0; i < 6; i++)
            OTP = OTP * 10 + (rand() % 10);
        FILE *file;
        file = fopen("../Data/OTP.txt", "w");
        fprintf(file, "%d", OTP);
        fclose(file);
        printf("Please enter the OTP sent to the number %s\n>>", number);
        scanf("%d", &E_OTP);
        if (E_OTP == OTP)
            return 1;
        printf("Incorrect OTP please try again!\n");
    }
}

void confirm(char seatindex[][3], char filepath[], int num)
{
    char final[3] = "NN\0";
    for (int i = 0; i < num; i++)
    {
        final[0] = seatindex[i][0];
        final[1] = seatindex[i][1];
        replace(filepath, final);
    }
}

void replace(char *filepath, char *position)
{
    int index = ((int)position[0] - 65) * 38 + 6 * ((int)position[1] - 48) + 36;
    FILE *file = fopen(filepath, "r+");
    fseek(file, index, SEEK_SET);
    fputc(' ', file);
    fputc('X', file);
    fclose(file);
}

void issue(int paid, char seat_index[][3], char filepath[], int choice)
{
    if (paid)
        confirm(seat_index, filepath, choice);
    else
    {
        invalid_input();
    }
}

int istaken(char filepath[], char position[])
{
    char c;
    int index = ((int)position[0] - 65) * 38 + 6 * ((int)position[1] - 48) + 37, output = 0;
    FILE *file = fopen(filepath, "r");
    fseek(file, index, SEEK_SET);
    if ((c = fgetc(file)) == 'X')
        output = 1;
    fclose(file);
    return output;
}

void generate(int *ID)
{
    srand(time(NULL));
    for (int i = 0; i < 9; i++)
        *ID = *ID * 10 + (rand() % 10);

}