#include <stdio.h>
void sum(int*, int, int*);
void sum(int* arr, int n, int* result) {

    int flag = 1;
    for(int i = 0;i < n; i++, flag = !flag) {
        if(flag)
            result[0]+=arr[i];
        else
            result[1]+=arr[i];
    }
}

void main() {
    int n;
    printf("Enter length of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements ;\n", n);
    for(int i = 0;i<n;i++) {
        scanf("%d", arr+i);
    }
    int result[] = {0, 0};
    sum(arr, n, result);
    printf("Odd Sum = %d\n", *result);
    printf("Even Sum = %d\n\n", *(result+1));
}