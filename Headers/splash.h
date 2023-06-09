#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <ctype.h>

void begin(void)
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
        usleep(150000);
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

void openJPG(const char *filename)
{
    HINSTANCE result = ShellExecute(NULL, "open", filename, NULL, NULL, SW_SHOW);
    
}

void map(void)
{
    char c;
    puts("Would you like to see a map of the layout of BlockPlex so you can have an easier time locating your hall?(Y/N))");
    scanf(" %c", &c);
    toupper(c);
    while (c != 'Y' && c != 'N' && c != 'y' && c != 'n')
    {
        fflush(stdin);
        printf("Invalid Response Please Try again\n>");
        scanf(" %c", &c);
    }
    if (c == 'Y' || c == 'y')
    {
        system("cls");
        printf("The hall name for your corresponding movie can be found on your ticket once you recieve them from the ticket booth");
        usleep(3000000);
        openJPG("..\\Data\\floorPlan.jpg");
    }
}