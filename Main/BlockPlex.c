#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../Headers/FileDisplay.h"
#include "../Headers/Booking.h"
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
        book_tickets(seat_index, &choice);
        paid = pay(choice);
        if (paid)
            confirm(filepath, seat_index, choice);
        else
            continue;
        puts("Your tickets have been confirmed! Thank You For Choosing BlockPlex.");

        break;
    }
    return 0;
}