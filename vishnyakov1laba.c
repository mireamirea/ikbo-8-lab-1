#include <stdio.h>
#include <stdlib.h>

#define PATH argv[1]

struct _file {
    int inum;
    char string[255];
    float fnum;
};

int main(int argc, const char * argv[]) {
    struct _file rf;
    char fpath[255];
    FILE *f = fopen(PATH, "r+b");
    while(f == NULL){
      printf("Enter file name or file path\n");
      scanf("%s", fpath);
    if ((f = fopen(fpath, "r+b")) == NULL) perror ("Error");
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
