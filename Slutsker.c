#include <stdio.h>

int main(int argc, char *argv[]){

struct stc  {
int n;
char s[255];
float f; } str;

char array [50];
FILE *file;
file=fopen(argv[1], "rb");

while (file == NULL){
printf(" Enter the name of file:  ");
scanf("%s", array);
file=fopen(array, "rb");
}

int filesize =0;

while (fread(&str, sizeof(struct stc), 1, file))
{
printf("%d\t %s\t %f\t\n",str.n, str.s, str.f);
filesize=filesize+sizeof(struct stc);
}

fclose(file);
printf("File size: %d bytes", filesize);
return 0;
}
