#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
struct Employee {
    int emp_id;
    char name[20];
    int sal;
};
int main () {
    FILE *of;
    of= fopen ("demo.txt", "w");
    if (of == NULL) {
        fprintf(stderr, "\nError to open the file\n");
        exit (1);
    }
    int n, i;
        printf("Enter the number of employees : ");
        scanf("%d", &n);
        struct Employee employess[n]; 
        for(i = 0;i<n;i++) {
            printf("\nEnter the name of employee %d : ", (i+1));
            scanf("%s", &employess[i].name);
            printf("Enter the id of employee %d : ", (i+1));
            scanf("%d", &employess[i].emp_id);
            printf("Enter the salary of employee %d : ", (i+1));
            scanf("%d", &employess[i].sal);
            fwrite(&employess[i], sizeof(struct Employee), 1, of);
        }

    if(fwrite != 0)
        printf("Contents to file written successfully !\n");
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
    int max = INT_MIN;
    while(fread(&inp, sizeof(struct Employee), 1, inf))
        if(inp.sal>=max)
            max = inp.sal;
    fclose (inf);
    inf = NULL;
    
    inf = fopen ("demo.txt", "r");
    if (inf == NULL) {
        fprintf(stderr, "\nError to open the file\n");
        exit (1);
    }
    printf("\n\nEmployee with greatest salary; \n");
    while(fread(&inp, sizeof(struct Employee), 1, inf))
        if(inp.sal==max)
            printf ("emp_id = %d name = %s salary = %d", inp.emp_id, inp.name, inp.sal);
    printf("\n\n");
    fclose (inf);
}