#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTH 255

typedef struct
{
    int number;
    char string[MAXLENGTH];
    float othernumber;
} readthing;


int main(int argc, const char * argv[]) {
    readthing *thing = malloc(sizeof(readthing));
    char path[MAXLENGTH];
    FILE *file;
    if (argc != 2)
    {
        printf("Enter the filepath\n");
        fgets(path, MAXLENGTH, stdin);
        path[strlen(path)-1] = '\0';
        if ((file = fopen(path, "r+b")) == NULL)
        {
            printf("file does not exist\n");
            return 0;
        }
        
    } else
        if ((file = fopen(argv[1], "r+b")) == NULL)
        {
            printf("file does not exist\n");
            return 0;
        }
    /*if ((file = fopen("/Users/denisskorobogatov/Desktop/lab1/lab1/data.dat", "r+b")) == NULL)
     {
     printw("file does not exist\n");
     endwin();
     return 0;
     }*/
    int i = 0;
    while (!feof(file))
    {
        fread(thing, sizeof(readthing), 1, file);
        printf("%d %s %f\n", thing->number, thing->string, thing->othernumber);
        i++;
    }
    printf("Element amount: %d\n", i-1);
    printf("File size: %ld\n", ftell(file));
    fclose(file);
    return 0;
}
