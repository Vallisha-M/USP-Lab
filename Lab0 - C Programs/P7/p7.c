#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Employee {
    int roll_no;
    char name[20];
    float cgpa;
};
int main () {
    FILE *of;
    of= fopen ("demo.txt", "w");
    if (of == NULL) {
            fprintf(stderr, "\nError to open the file\n");
            exit (1);
    }
    int n, i;
    printf("Enter the number of students : ");
    scanf("%d", &n);
    struct Employee students[n]; 
    for(i = 0;i<n;i++) {
        printf("\nEnter the name of student %d : ", (i+1));
        scanf("%s", &students[i].name);
        printf("Enter the roll number of student %d : ", (i+1));
        scanf("%d", &students[i].roll_no);
        printf("Enter the CGPA of student %d : ", (i+1));
        scanf("%f", &students[i].cgpa);
        fwrite(&students[i], sizeof(struct Employee), 1, of);
    }
    if(fwrite != 0)
        printf("\nContents to file written successfully !\n");
    else
        printf("Error writing file !\n");
    fclose (of);
    FILE *inf;
    struct Employee inp;
    inf = fopen ("demo.txt", "r");
    if (inf == NULL) {
        fprintf(stderr, "\nError to open the file\n");
        exit (1);
    }
    printf("\n\nStudents with less than 5.0 CGPA;\n");
    while(fread(&inp, sizeof(struct Employee), 1, inf))
        if(inp.cgpa<5)
            printf ("roll_no = %d name = %s cgpa = %f\n", inp.roll_no, inp.name, inp.cgpa);
    printf("\n\n");
    fclose (inf);
}