#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    struct packet {
        int x;
        char y[255];
        float z;
    } a;
    FILE *file;
    int i = 0;
    printf("File name: ");
    //scanf("%s\n", &adr);
    if (!(file = fopen(argv[1], "rb")))
        return -1;
    while (fread(&a, sizeof(struct packet), 1, file)){
        printf(" %d  %s  %f \n", a.x, a.y, a.z);
        i++;
    }
    printf("File size = %dbyte\n", sizeof(struct packet)*i);
    fclose(file);
    return 0;
}
