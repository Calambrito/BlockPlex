#include <stdio.h>
#include <string.h>
#include "../Headers/FileDisplay.h"
int main(void)
{
    int choice;
    char filepath[] = "../Data/Movie-$.txt", seat_index[3] = "HH\0";
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
        filepath[14] = (char)(choice + 48);
        read_file(filepath);
        if (choice == 4)
        {
            usleep(1300000);
            continue;
        }
        scanf(" %c%c", &seat_index[0], &seat_index[1]);
        replace_value_in_file(filepath, seat_index);
        break;

    }
    return 0;
}