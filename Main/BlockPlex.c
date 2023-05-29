#include <stdio.h>
#include <string.h>
#include "../Headers/FileDisplay.h"
int main(void)
{
    int choice;
    char filename[40], seat_index[2], *fpath;
    fpath = filename;
    while (1)
    {
        begin();
        read_file("../Data/NowShowing.txt");
        scanf("%d", &choice);
        if (choice > 4 || choice < 1)
        {
            invalid_input();
            continue;
        }
        sprintf(filename, "../Data/Movie-%d.txt", choice);
        read_file(filename);
        if (choice == 4)
            continue;
        sprintf(filename, "../Data/Movie-%d.txt", choice);
        scanf(" %s", seat_index);
        replace_value_in_file(fpath, seat_index);
        break;
    }
    return 0;
}
