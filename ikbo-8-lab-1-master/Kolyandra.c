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
    char path[255];
    struct packet pk;
    f = fopen(argv[1],"r+b");
    while (f == NULL){
    	printf("Enter file name or path\n");
    	scanf("%s",path);
    	f = fopen(path,"r+b");
   		}
    while (fread(&pk, sizeof(struct packet),1,f)){
        printf("%d  %s  %f\n",pk.x,pk.str,pk.flnum);
        i++;
    }
    printf ("Size of file: %zd",i*sizeof(struct packet));
    fclose(f);
    return i;
}
