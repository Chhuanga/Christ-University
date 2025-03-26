// Program to read data

#include <stdio.h>
#include <stdlib.h>

int main() {
    char str1[100]; 
    int a, b, c, d, e;
    FILE *fptr;

    printf("Reading from File\n");
    fptr = fopen("data.txt", "r");

    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fscanf(fptr, "%s %d %d %d %d %d", str1, &a, &b, &c, &d, &e);
    printf("%s %d %d %d %d %d\n", str1, a, b, c, d, e);

    fclose(fptr);
    return 0;
}