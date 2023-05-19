#include <stdio.h>
#include "../Headers/FileDisplay.h"
int main(void)
{
    int choice,row,column;
    char filename[40];
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
        break;
    }
    return 0;
}
