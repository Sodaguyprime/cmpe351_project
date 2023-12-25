#include <stdio.h>
#include <stdlib.h>

void takedata(const char *filename);

int main() {
    takedata("text.txt");

    return 0;
}

void takedata(const char *Filename) {

    FILE *fh = fopen(Filename, "r");

    if (fh !=NULL)
{
    char c;
    while ((c= fgetc(fh)) != EOF) 
    {
     putchar(c);
    }
    fclose(fh);

}else printf("Error opening file.\n");

  FILE *fp;
  fp = fopen("output.txt", "w");

  fclose(fp);
  
}