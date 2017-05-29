#include <stdio.h>
#include <stdlib.h>
#define maxL 255

typedef struct{
    int m;
    char arr[maxL];
    float a;} x;



int main(int argc, const char * argv[]){
    FILE *file;

    x * y = malloc(sizeof(x));
    if (argc != 2)
    {
        printf("need args\n");
        return 0;
    }


    if ((file = fopen(argv[1], "r+b"))== NULL)
    {
        printf("file does not exist\n");
        return 0;
    }

/*if ((file = fopen("Users/Àíòîí/Desktop/data.DAT", "r+b")== NULL)
      {
      printf("file does not exist\n");
        return 0;
      }*/

    int i=0;
    while (!feof(file))
    {
        fread(y, sizeof(x), 1, file);
        printf("%d %s %f\n", y -> m, y -> arr, y -> a);
        i++;
    }

    fseek(file, 0, SEEK_END);
    printf("Elements count: %d\n", i-1 );
    printf("File size: %ld bytes", ftell(file));
    fclose(file);

    return 0;

}
