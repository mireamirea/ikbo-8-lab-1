#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _PathLength 255

typedef struct {
    int intnumber;
    char string[_PathLength];
    float fltnumber;
} readfile;

int main(int argc, const char * argv[]) {
    readfile *thing = malloc(sizeof(readfile));
    char path[_PathLength];
    FILE *file;
    printf("Enter the path to the file\n");
    fgets(path, _PathLength, stdin);
    path[strlen(path)-1] = '\0';
    if ((file = fopen(path, "r+b")) == NULL) {
        printf("Path is incorrect or file does not exist\n");
        return 0;
    }
    
    int i = 0;
    while (!feof(file)) {
        fread(thing, sizeof(readfile), 1, file);
        printf("%d %s %f\n", thing->intnumber, thing->string, thing->fltnumber);
        i++;
    }
    
    printf("Element amount: %d\n", i-1);
    printf("File size: %ld byte\n", ftell(file));
    fclose(file);
    return 0;
}
