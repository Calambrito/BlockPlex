#include <stdio.h>

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

void replace_value_in_file(const char *filename, const char *position)
{
    FILE *file = fopen(filename, "r+");
    if (file != NULL)
    {
        char line[256];
        char *found;
        long filePosition = -1;
        int lineNumber = 1;
        while (fgets(line, sizeof(line), file) != NULL)
        {
            found = strstr(line, position);
            if (found != NULL)
            {
                filePosition = (found - line);
                break;
            }
            lineNumber++;
        }
        if (filePosition != -1)
        {
            fseek(file, filePosition + 1, SEEK_SET);
            fputc('X', file);
            fseek(file, filePosition, SEEK_SET);
            fputc(' ', file);
            printf("Value replaced at line %d.\n", lineNumber);
        }
        else
        {
            printf("Position not found in the file.\n");
        }
        fclose(file);
    }
    else
    {
        printf("Failed to open the file.\n");
    }
}