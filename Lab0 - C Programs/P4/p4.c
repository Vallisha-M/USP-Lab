#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct node {
    int data;
    struct node* next;
}node;

void arraySplit(int* a, node* result[],int* resultN, int n) {
    node* headB = NULL;
    node* headC = NULL;
    node* prevB = NULL;
    node* prevC = NULL;
    int b = 0;
    int c = 0;
    for(int i = 0; i<n; i++) {
        if(a[i]%2!=0) {
            node* curr = (node*) malloc(sizeof(node));
            curr->data = a[i];
            if(headB==NULL){
                headB = curr;
                prevB = curr;
            }
            b+=1;
            prevB->next = curr;
            prevB = curr;
        }
        else {
            node* curr = (node*) malloc(sizeof(node));
            curr->data = a[i];
            if(headC==NULL){
                headC = curr;
                prevC = curr;
            }
            c+=1;
            prevC->next = curr;
            prevC = curr;
        }
    }
    result[0]=headB;
    result[1]=headC;
    resultN[0]=b;
    resultN[1]=c;
}

void main() {
    node* result[] = {NULL, NULL};
    int resultN[] = {0, 0};
    int n;
    printf("Enter length of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements ;\n", n);
    int i;
    for(i = 0;i<n;i++) {
        scanf("%d", arr+i);
    }
    arraySplit(arr, result, resultN, n);
    int b[resultN[0]];
    int c[resultN[1]];
    node* curr = result[0];
    i = 0;
    while(curr!=NULL) {
        b[i] = curr->data;
        curr = curr->next;
        i+=1; 
    }
    curr = result[1];
    int min, max, sum;
    sum = 0;
    min = INT_MAX;
    max=INT_MIN;
    i = 0;
    while(curr!=NULL) {
        if(curr->data>max)
            max = curr->data;
        if(curr->data<min)
            min = curr->data;
        sum += curr->data;
        c[i] = curr->data;
        curr = curr->next;
        i+=1;
    }
    float avg = (resultN[1]>0)?sum / resultN[1]:0;
    printf("Array B : ");
    for(i = 0;i<resultN[0];i++)
        printf("%d  ", b[i]);
    printf("\n\n");
    printf("Array C : ");
    for(i = 0;i<resultN[1];i++)
        printf("%d  ", c[i]);
    printf("\n\n");
    printf("Minimum of array C : %d", min);
    printf("\nMaximum of array C : %d", max);
    printf("\nSum of array C : %d", sum);
    printf("\nAverage of array C : %f\n\n", avg);

}