#include <stdio.h>
#include "../Headers/FileDisplay.h"
int main()
{
    int choice;
    while (1)
    {
        begin();
        read_file("../Data/NowShowing.txt");
        scanf("%d", &choice);
        if (choice > 4 || choice < 1)
        {
            invalid_input();
            scanf("%*s");
            continue;
        }
    }
}
