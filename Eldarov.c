#include <stdio.h>

struct packet {
int x;
char string[255];
float floatingpointnumber;
};

int main(int argc, char** argv)
{
    char path[255];
    FILE *f;
    struct packet packet1;
    if (argc != 2) /*(! (f = fopen("data.dat", "rb")))*/
    {
        printf("Enter the path to file (data.dat): ");
        scanf("%s",path);
    if (!(f = fopen(path, "rb")))
        {
            printf("File don't exist\n");
            return 0;
        }

    } else
    if (!(f = fopen(argv[1], "rb")))
    {
        printf("File don't exist\n");
    }

    int i = 0;
    printf("\n Num. of Str: \t            String:\t          Floating point number: \n");
    while(fread(&packet1, sizeof(struct packet), 1, f))
    {
        printf("      %d       | %s |     %f      |\n", packet1.x, packet1.string, packet1.floatingpointnumber);
        i++;
    }
    printf("-------------------------------------------------------------------------");
    printf("\n\t\t\t Filesize: %lu\n", i * sizeof(struct packet));
    fclose(f);
    return 1;
}
