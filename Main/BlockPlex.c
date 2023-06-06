#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../Headers/menu.h"
#include "../Headers/splash.h"
#include "../Headers/login.h"

int main(void)

{
    Profile Member;
    int choice, paid = 0, discount = 1, bookingID;
    char filepath[] = "../Data/Movie-$.txt", seat_index[36][3];
    while (1)
    {
        fflush(stdin);
        begin();
        read_file("../Data/NowShowing.txt");
        scanf("%d", &choice);
        if (choice > 5 || choice < 1)
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
        member(Member, &discount);
        paid = pay(choice, discount);
        issue(paid, seat_index, filepath, choice);
        if (!paid)
        {
            usleep(1300000);
            continue;
        }
        printf("\nYour tickets have been confirmed! Thank You For Choosing BlockPlex.\n");
        generate(&bookingID);
        printf("Here is your confidential booking ID, bring it to any BlockPlex ticket booth to recieve your tickets.\nBooking ID: %d\n\n", bookingID);
        map();
        break;
    }
    return 0;
}