#include <stdio.h>

struct panda{
	int intnum;
	char array[255];
	float floatnum;
};

int main(void){
	struct panda milota;
	int i;
	FILE *f = NULL;
	char filename[100];
	f = 0;
	while (f == NULL){
		printf("Vvedite imya faila: ");
		scanf("%s", filename);
		f = fopen(filename, "rb");
	}
	i = 0;
	while(fread(&milota, sizeof(struct panda), 1, f)){ 
		printf("| %d | %s | %f |\n", milota.intnum, milota.array, milota.floatnum); 
		i++;
	}
	fclose(f);
	return i * sizeof(struct panda);
}
