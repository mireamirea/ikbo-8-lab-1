/*Kolyandra*/
#include <stdio.h>
#include <stdlib.h>


struct packet {
    int x;
    char str[255];
    float flnum;
}packet;


int main(int argc, char *argv[]) {
    FILE *f;
    int i = 0;
    struct packet pk;
    if(argc != 2) {
        printf("Write patch to the file\n");
        exit(1);
    }
    if (!(f = fopen(argv[1],"r+b"))){
        printf("Error");
        return -1;
    }
    while (fread(&pk, sizeof(struct packet),1,f)){
        printf("%d  %s  %f\n",pk.x,pk.str,pk.flnum);
        i++;
    }
    printf ("Size of file: %d",i*sizeof(struct packet));
    fclose(f);
    return i;
}
