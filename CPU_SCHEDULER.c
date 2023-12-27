#include <stdio.h>
#include <stdlib.h>

//declaring the functions below
//void takedata(const char *filename);
int countlines(const char *filename);




//main function
int main() {
    
    //takedata("text.txt");// for testing right now
    int choice;
    do{
    printf("                         %s", "CPU SCHEDULER SIMULATOR""\n");
    printf("1) Scheduling Method (None)\n");
    printf("2) Preemptive Mode(off)\n");
    printf("3) Show Result)\n");
    printf("4) End Program\n");

   
    scanf("%d",&choice);
    switch (choice) {
        case 1:
            printf("Scheduling Method\n");
            break;
        case 2:
            printf("Preemptive Mode\n");
            break;
        case 3:
            printf("Show Result\n");
            break;
        case 4:
            printf("Exiting.......\n");
            return 0;
        default:
            printf("Invalid choice\n");
    }

    }while(choice!=4);
    int lines = (countlines("text.txt"))-1;    
    return 0;
}

















// user-defined functions
/* void takedata(const char *filename) {

    FILE *fh = fopen(filename, "r");
    int lines =  countlines("text.txt");
    if (fh !=NULL)
{
    int c;
    while ((c= fgetc(fh)) != EOF) 
    {
    int Table_array[lines][3];   

    for (int i=0;i<lines;i++){
        for (int j=0;j<3;j++){
        fscanf(fh,"%d",Table_array[i][j]);
        }
    }


     for (int o = 0; o < lines; o++) {
        for (int p = 0; p < 3; p++) {
            printf("%d ", Table_array[o][p]);
        }
        printf("\n");
    }


    }
    fclose(fh);

}else printf("Error opening file.\n");

  FILE *fp;
  fp = fopen("output.txt", "w");

  fclose(fp);
  
} */



int countlines(const char *filename){
    int count = 1 ;
    char D;
    FILE *fh = fopen(filename, "r");

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