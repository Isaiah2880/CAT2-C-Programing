/*
NAME:ISAIAH OTIENO 
REGISTRATION NUMBER:PA106/G/28801/25
DESCRIPTION:Function that takes data input, stores the data, read, display contents and ensure appropriate error handling when opening to files 
*/

#include <stdio.h>
#include <stdlib.h>

// Function to input 10 integers and store them in input.txt
void writeInputFile() {
    FILE *fptr;
    int num, i;

    fptr = fopen("input.txt", "w");
    if (fptr == NULL) {
        printf("Error opening input.txt for writing!\n");
        exit(1);
    }

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        printf("Integer %d: ", i + 1);
        scanf("%d", &num);
        fprintf(fptr, "%d\n", num);
    }

    fclose(fptr);
    printf("Data successfully written to input.txt\n\n");
}

// Function to read integers, compute sum and average, and write to output.txt
void processFiles() {
    FILE *fin, *fout;
    int num, sum = 0, count = 0;
    float average;

    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("Error opening input.txt for reading!\n");
        exit(1);
    }

    while (fscanf(fin, "%d", &num) == 1) {
        sum += num;
        count++;
    }
    fclose(fin);

    if (count == 0) {
        printf("No data found in input.txt!\n");
        exit(1);
    }

    average = (float)sum / count;

    fout = fopen("output.txt", "w");
    if (fout == NULL) {
        printf("Error opening output.txt for writing!\n");
        exit(1);
    }

    fprintf(fout, "Sum = %d\nAverage = %.2f\n", sum, average);
    fclose(fout);

    printf("Sum and average written to output.txt\n\n");
}

// Function to display the contents of both files
void displayFiles() {
    FILE *fin, *fout;
    char ch;

    printf("Contents of input.txt:\n");
    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("Error opening input.txt for reading!\n");
        exit(1);
    }
    while ((ch = fgetc(fin)) != EOF)
        putchar(ch);
    fclose(fin);

    printf("\nContents of output.txt:\n");
    fout = fopen("output.txt", "r");
    if (fout == NULL) {
        printf("Error opening output.txt for reading!\n");
        exit(1);
    }
    while ((ch = fgetc(fout)) != EOF)
        putchar(ch);
    fclose(fout);
    printf("\n");
}

// Main function
int main() {
    writeInputFile();
    processFiles();
    displayFiles();
    return 0;
}
