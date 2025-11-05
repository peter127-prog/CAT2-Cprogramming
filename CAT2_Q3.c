/*
name:peter thagana
reg:CT100/G/26164/25
desc:A program to reads integers from a file ,processes and writes them in a diifernt file.
*/

#include <stdio.h>

#include <stdlib.h>


void writeIntegersToFile();
void processIntegers();
void displayFiles();

int main() {
    writeIntegersToFile();
    processIntegers();
    displayFiles();
    return 0;
}


void writeIntegersToFile() {
    FILE *fp;
    int i, num;

    fp = fopen("input.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        exit(1);
    }

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &num);
        fprintf(fp, "%d\n", num);
    }

    fclose(fp);
    printf("Numbers have been saved to input.txt\n\n");
}


void processIntegers() {
    FILE *inFile, *outFile;
    int num, sum = 0, count = 0;
    float average;

    inFile = fopen("input.txt", "r");
    if (inFile == NULL) {
        printf("Error opening input.txt for reading!\n");
        exit(1);
    }

    while (fscanf(inFile, "%d", &num) != EOF) {
        sum += num;
        count++;
    }
    fclose(inFile);

    if (count == 0) {
        printf("No numbers found in input.txt\n");
        exit(1);
    }

    average = (float)sum / count;

    outFile = fopen("output.txt", "w");
    if (outFile == NULL) {
        printf("Error opening output.txt for writing!\n");
        exit(1);
    }

    fprintf(outFile, "Sum = %d\nAverage = %.2f\n", sum, average);
    fclose(outFile);

    printf("Results written to output.txt\n\n");
}


void displayFiles() {
    FILE *fp;
    char ch;

    printf("Contents of input.txt:\n");
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening input.txt for reading!\n");
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);
    fclose(fp);

    printf("\nContents of output.txt:\n");
    fp = fopen("output.txt", "r");
    if (fp == NULL) {
        printf("Error opening output.txt for reading!\n");
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);
    fclose(fp);
}