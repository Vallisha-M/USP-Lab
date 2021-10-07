#include <stdio.h>
void details(int*, int, int*);

void details(int* arr, int n, int* result) {
    for(int i = 0 ; i < n ; i++) {
        if(arr[i] > 0)
            result[2]+=1;
        else if(arr[i] < 0)
            result[0]+=1;
        else
            result[1]+=1;
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
    int result[] = {0, 0, 0};
    details(arr, n, result);
    printf("Number of Negative Elements in the Array : %d\n", result[0]);
    printf("Number of Zeroes in the Array : %d\n", result[1]);
    printf("Number of Positive Elements in the Array : %d\n\n", result[2]);
}