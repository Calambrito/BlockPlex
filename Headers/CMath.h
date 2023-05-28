#include <stdio.h>
#include <string.h>

void replace_value_in_file(const char* filename, const char* position) {
    FILE* file = fopen(filename, "r+");
    
    if (file != NULL) {
        char line[256];
        char* found;
        long filePosition = -1;
        int lineNumber = 1;      
        while (fgets(line, sizeof(line), file) != NULL) {
            found = strstr(line, position);           
            if (found != NULL) {
                filePosition = ftell(file) - strlen(line) + (found - line);
                break;
            }            
            lineNumber++;
        }        
        if (filePosition != -1) {
            fseek(file, filePosition, SEEK_SET);
            fputc('X', file);
            printf("Value replaced at line %d.\n", lineNumber);
        } else {
            printf("Position not found in the file.\n");
        }        
        fclose(file);
    } else {
        printf("Failed to open the file.\n");
    }
}