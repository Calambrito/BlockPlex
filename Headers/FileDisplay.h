#include <stdio.h>
#include <string.h>
#include <unistd.h>
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

void replace_value_in_file(const char *filepath, const char *position)
{
    int index = ((int)position[0] - 65) * 36 + 2 * ((int)position[0] - 65) + 6 * ((int)position[1] - 48) - 2;
    FILE *file = fopen(filepath, "r+");
    fseek(file, index, SEEK_SET);
    fputc(' ', file);
    fputc('X', file);
    fclose(file);
}
