#include <stdio.h>
#include <string.h>
#define max 100

int main() {
    char str[max];
    int i, length;

    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Can't open the input file for reading.\n");
        return 1;
    }
    fscanf(inputFile, "%s", str);
    fclose(inputFile);

    length = strlen(str);
    int isAccepted = 0;
    if (length >= 2 && str[length - 1] == str[length - 2]) {
        isAccepted = 1;
    }

    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Can't open output file for writing.\n");
        return 1;
    }

    if (isAccepted)
        fprintf(outputFile, "String ending with two symbols of same type is accepted");
    else
        fprintf(outputFile, "String ending with two symbols of same type is not accepted");

    fclose(outputFile);

    printf("Input from input.txt has been processed, and the result has been written to output.txt\n");

    return 0;
}
