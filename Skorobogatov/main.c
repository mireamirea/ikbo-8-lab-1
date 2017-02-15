#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define MAXLENGTH 255

typedef struct
{
    int number;
    char string[MAXLENGTH];
    float othernumber;
} readthing;


int main(int argc, const char * argv[]) {
    initscr();
    readthing *thing = malloc(sizeof(readthing));
    FILE *file;
    /*if (argc != 2)
    {
        printf("need args\n");
        return 0;
    }
    if ((file = fopen(argv[1], "r+b")) == NULL)
    {
        printf("file does not exist\n");
        return 0;
    }*/
    if ((file = fopen("/Users/denisskorobogatov/Desktop/lab1/lab1/data.dat", "r+b")) == NULL)
     {
         printw("file does not exist\n");
         endwin();
     return 0;
     }
    int i = 0;
    while (!feof(file))
    {
        fread(thing, sizeof(readthing), 1, file);
        printw("%d %s %f\n", thing->number, thing->string, thing->othernumber);
        i++;
        refresh();
    }
    // fseek(file,0,SEEK_END);
    printw("Element amount: %d\n", i-1);
    printw("File size: %ld\n", ftell(file));
    refresh();
    endwin();
    fclose(file);
    return 0;
}
