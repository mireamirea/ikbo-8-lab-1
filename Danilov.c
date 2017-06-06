#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int size=0;
    struct dadaya{
int c;
char arr[255];
float fl;} str;

    FILE *file;

	file = fopen(argv[1], "rb");

    while (fread(&str, sizeof(struct dadaya), 1,file)){
		printf("%d    %s    %f\n", str.c,str.arr,str.fl);
		size=size+sizeof(struct dadaya);
    }
    fclose(file);
    printf("%d bytes", size);
    return 0;

}
