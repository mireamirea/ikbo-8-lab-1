#include <stdio.h>
#include <stdlib.h>

struct _file {
    int inum;
    char string[255];
    float fnum;
};

int main(int argc, const char * argv[]) {
    struct _file rf;
    char fpath[255];
    FILE *f;
    while(f == NULL){
    if (argc != 2){
    printf("Enter file name or file path\n");
    fgets(fpath, 255, stdin);
    fpath[strlen(fpath)-1] = 0;
    if ((f = fopen(fpath, "r+b")) == NULL) perror ("Error 228");
   }else if ((f = fopen(argv[2], "r+b")) == NULL) perror ("Error 228");
    }
    int i = 0;
    while (!feof(f)) {
        fread(&rf, sizeof(rf), 1, f);
        printf("%d %s %f\n", rf.inum, rf.string, rf.fnum);
        i++;
    }
    printf("Element amount: %d\n", i-1);
    printf("File size: %ld byte/-s\n", ftell(f));
    fclose(f);
    return 0;
}
