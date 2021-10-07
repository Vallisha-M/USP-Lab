#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    FILE* fp;
    char filename[100];
    char toBeWritten[100];
    printf("Enter a filename : ");
    fgets(filename, 100, stdin);
    printf("Enter a string to write : ");
    fgets(toBeWritten, 100, stdin);
    fp = fopen(filename, "w");
    if(fp)
        fputs(toBeWritten, fp);
    else {
        printf("\n\nError writing to file\n\n");
        fclose(fp);
        exit(0);
    }
    fclose(fp);
    printf("\n\n--File Write Successful--\n\n");
    fp = NULL;
    fp = fopen(filename, "r");
    char str[100];
    if(fp) {
        if(fgets (str, 100, fp)!=NULL)
            printf("\n\nString in file : %s", str);
        else {
            printf("\n\nError opening the file\n\n");
            fclose(fp);
            exit(0);
        }
    }
    else {
            printf("\n\nError opening the file\n\n");
            fclose(fp);
            exit(0);
    }
    printf("\n\n--File Read Successfull--\n\n");
}