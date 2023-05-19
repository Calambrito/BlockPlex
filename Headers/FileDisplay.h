#include <stdio.h>
#include <stdlib.h>

void begin()
{
    FILE *file;
    char filename[48];
    char ch;

    for (int i = 1; i <= 10; i++)
    {
        system("cls");
        sprintf(filename, "../ASCII/LogoFrame-%d.txt", i);

        file = fopen(filename, "r");

        while ((ch = fgetc(file)) != EOF)
        {
            putchar(ch);
        }
        printf("\n\n");
        usleep(80000);
    }
}

void read_file(char filePath[])
{
    FILE *file = fopen(filePath, "r");
    int ch;
    while ((ch = fgetc(file)) != EOF)
    {
        putchar(ch);
    }
    fclose(file);
}

void invalid_input()
{
    system("cls");
    read_file("../ASCII/InvalidChoice.txt");
    usleep(1300000);
    system("cls");
}