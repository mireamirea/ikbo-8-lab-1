#include <stdio.h>

struct panda{
	int intnum;
	char array[255];
	float floatnum;
};

int main(int argc, char *argv[]){
	struct panda milota;
	int i;
	FILE *f = NULL;
	char filename[100];
	f=fopen(argv[1], "rb");
	while (f == NULL){
		printf("Vvedite imya faila: ");
		scanf("%s", filename);
		f = fopen(filename, "rb");
	}
	i = 0;
	printf("Tablitsa:\n");
	while(fread(&milota, sizeof(struct panda), 1, f)){ 
		printf("| %d | %s | %f |\n", milota.intnum, milota.array, milota.floatnum); 
		i=i+sizeof(struct panda);
	}
	printf("Razmer faila: %d B",i);
	fclose(f);
	return 0;
}
