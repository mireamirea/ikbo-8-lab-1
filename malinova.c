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
    int j = -1;
    while(j==(-1)){
        if (!(file = fopen(argv[1], "rb"))){
            printf("File name: ");
            scanf("%s", &argv[1]);
        }
        else j = 0;
    }
    while (fread(&a, sizeof(struct packet), 1, file)){
        printf(" %d  %s  %f \n", a.x, a.y, a.z);
        i++;
    }
    printf("File size = %d byte\n", sizeof(struct packet)*i);
    fclose(file);
    return 0;
}
