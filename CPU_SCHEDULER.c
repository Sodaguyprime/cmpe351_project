#include <stdio.h>
#include <stdlib.h>

void takedata(const char *filename);

int main() {
    // Call the user-defined function with the filename
    takedata("text.txt");

    return 0; // Return success
}

void takedata(const char *Filename) {

    FILE *file = fopen(Filename, "r");

    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}

