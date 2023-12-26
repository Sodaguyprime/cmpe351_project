#include <stdio.h>
#include <stdlib.h>

//declaring the functions below
void takedata(const char *filename);
int countlines(const char *Filename);

//main function
int main() {
    
    
    takedata("text.txt");// for testing right now


    return 0;
}
















// user-defined functions
void takedata(const char *Filename) {

    FILE *fh = fopen(Filename, "r");
    int lines =  countlines("text.txt");
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

int countlines(const char *Filename){
    int count = 1 ;
    char D;
    FILE *fh = fopen(Filename, "r");

    do
    {
        D = fgetc(fh);
        if (D== '\n'){
            count++;
        }
    }while (D !=EOF);

    fclose(fh);
    return count;
}