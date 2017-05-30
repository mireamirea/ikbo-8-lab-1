#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
	
	if (argc != 2)
    {
        printf("error\n");
        return 0;
    }
	
	int x;
	
	typedef struct{
    	int decement;
    	char string[255];
    	float sin_prec;
	} read_string;
    
	read_string *stroka = malloc(sizeof(read_string));
    
	FILE *file;
    
	if ((file = fopen(argv[1], "r+b")) == NULL)
    {
        printf("error\n");
        return -1;
    }

    while (1)
    {
        fread(stroka, sizeof(read_string), 1, file);
        printf("%d %s %f\n", stroka->decement, stroka->string, stroka->sin_prec);
	
	    if(!feof(file))
		    break;
    }

    printf("Size of file: %ld bytes\n", ftell(file));
    fclose(file);
    return 0;
}
