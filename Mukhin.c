#include <stdio.h>
#include <stdlib.h>


struct packet {
    int x;
    char masive[255];
    float o;
}ST;


int main(int argc, char *argv[]) {
    FILE *FILE;

    int f = 0;
    char name[255];

    FILE = fopen(argv[1],"r+b");

    while (FILE == NULL){
    	printf("Enter file name \n");
    	scanf("%s",name);
    	FILE = fopen(name,"r+b");
   		}
    while (fread(&ST, sizeof(struct packet),1,FILE)){
        printf("%d  %s  %f\n",ST.x,ST.masive,ST.o);
        f++;
    }
    printf ("SizeF: %zd",f*sizeof(struct packet));
    fclose(FILE);
    return f;
}
