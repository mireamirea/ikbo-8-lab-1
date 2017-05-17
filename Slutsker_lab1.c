#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX 255



int main(int argc, char **argv) {

    
    struct {
        int num;
        char string[MAX];
        float fnum;
    } rFile;
    
    FILE *f;
    char array[MAX];

    if ( argc != 2 || ((f = fopen(argv[1], "rb")) == NULL) ) {
    	printf("Enter the path to the file\n");

    	while (1) {
    		scanf("%s", array);
    		if ((f = fopen(array, "r+b")) != NULL) 
			break;

            
    		else printf("Wrong name\n");
    	}

    }


   
    int i = 0;

    while(!feof(f)) {

        fread(&rFile, sizeof(rFile), 1, f);
        printf("%d %s %f\n", rFile.num, rFile.string, rFile.fnum);

        i++;
    }

    
    fseek(f,0,SEEK_END);
    printf("Elements count: %d\n", i - 1);
    printf("File size: %ld\n bytes", ftell(f));
	fclose(f);
    
    return 0;
}	 		 	 	  		 	 	 	 	  																																																																																																																										
