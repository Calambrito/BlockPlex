#include <stdio.h>
#include <string.h>
#include "../Headers/FileDisplay.h"
int main(void)
{
    int choice;
    char filename[] = "../Data/Movie-$.txt", seat_index[3] = "HH\0";
    while (1)
    {
        begin();
        read_file("../Data/NowShowing.txt");
        scanf("%d", &choice);
        fflush(stdin);
        if (choice > 4 || choice < 1)
        {
            invalid_input();
            continue;
        }
        filename[14] = (char)(choice + 48);
        read_file(filename);
        if (choice == 4)
        {
            usleep(1300000);
            continue;
        }
        scanf(" %c%c", &seat_index[0], &seat_index[1]);
        puts(filename);
        puts(seat_index);
        replace_value_in_file(filename, seat_index);
        break;
    }
    return 0;
}