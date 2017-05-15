#include <stdio.h>
#include <stdlib.h>


struct st {
	
	int a;
	char s[255];
	float b;
	
} q;



int main (int argc, const char * argv[]) {
	
	FILE *fp;
	
	
	/* Error checking */
	
	if (argc != 2) {
		
        printf("Error\n");
        return 0;
    }
    
	if ((fp = fopen(argv[1], "rb")) == NULL) {
		
        printf("Error\n");
        return 0;
    }
	
	
	/* Reading data */
	
	while(!feof(fp)) {
	
		fread(&q, sizeof(struct st), 1, fp);
		printf("%6.1d    %s    %f\n", q.a, q.s, q.b);
		
	}
	
	
	/* File size calculation */
	
	long size = ftell(fp);
	printf("\nFile size = %ld bytes\n", size);
	
	
	fclose(fp);
	
	
	return 0;
}
