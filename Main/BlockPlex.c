#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../Headers/menu.h"
#include "../Headers/splash.h"

int main(void)
{
    int choice, paid;
    char filepath[] = "../Data/Movie-$.txt", seat_index[36][3];
    while (1)
    {
        fflush(stdin);
        begin();
        read_file("../Data/NowShowing.txt");
        scanf("%d", &choice);
        if (choice > 4 || choice < 1)
        {
            invalid_input();
            continue;
        }
        filepath[14] = (char)(choice + 48);
        read_file(filepath);
        if (choice == 4)
        {
            usleep(1300000);
            continue;
        }
        book_tickets(seat_index, &choice, filepath);
        paid = pay(choice);
        issue(paid, seat_index, filepath, choice);
        if (!paid)
        {
            usleep(1300000);
            continue;
        }
        printf("\nYour tickets have been confirmed! Thank You For Choosing BlockPlex.\n");

        break;
    }
    return 0;
}