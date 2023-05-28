#include <stdio.h>
#include <string.h>
#include "../Headers/FileDisplay.h"
#include "../Headers/CMath.h"
int main(void)
{
    int choice;
    char filename[40], seat_index[2];
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
        if(choice == 4)
        continue;
        scanf("%s", &seat_index);
        replace_value_in_file("../Data/Movie-1.txt",seat_index);
        break;
    }
    return 0;
}
