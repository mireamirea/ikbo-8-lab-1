#include <stdio.h>

struct packet {
int x;
char string[255];
float floatingpointnumber;
};

int main()
{
    FILE *f;
    struct packet packet1;
    if (! (f = fopen("data.dat", "rb")))
    {
        return printf("Can't find file of can't open file!\nPlease, try again...");
    }
    int i = 0;
    printf(" Num. of Str: \t            String:\t          Floating point number: \n");
    while(fread(&packet1, sizeof(struct packet), 1, f))
    {
        printf("      %d       | %s |     %f      |\n", packet1.x, packet1.string, packet1.floatingpointnumber);
        i++;
    }
    printf("-------------------------------------------------------------------------");
    printf("\n\t\t\t Filesize: %d\n", i * sizeof(struct packet));
    fclose(f);
    return 0;
}
