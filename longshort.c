#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Must supply a source and two destination files.\n");
        exit(1);
    }

    FILE *srcFile = fopen(argv[1], "r");
    if (!srcFile)
    {
        printf("Can't open %s for reading\n", argv[1]);
        exit(1);
    }

    FILE *destFile1 = fopen(argv[2], "w");
    if (!destFile1)
    {
        printf("Can't open %s for writing\n", argv[2]);
        exit(1);
    }

    FILE *destFile2 = fopen(argv[3], "w");
    if (!destFile2)
    {
        printf("Can't open %s for writing\n", argv[3]);
        exit(1);
    }

    char line[1000];
    while (fgets(line, sizeof(line), srcFile) != NULL)
    {  
        if (strlen(line) < 20)
        {
            for (int i=0; line[i] != '\0'; i++)
            {
                line[i] = toupper(line[i]);
            }
            fprintf(destFile1, "%s", line);
        }
        
        else
        {
            for (int i=0; line[i] != '\0'; i++)
            {
                line[i] = tolower(line[i]);
            }
            fprintf(destFile2, "%s", line);
        }
        
    }

    fclose(srcFile);
    fclose(destFile1);
    fclose(destFile2);
}