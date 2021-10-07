#include <stdio.h>
void bill(int*, int*, int, int*);

void bill(int* quantities, int* priceList, int n, int* result) {
    for(int i = 0; i < n; i++)
        result[0] += (priceList[i] >=0 && quantities[i]>=0)?(priceList[i]*quantities[i]):0;
    if(result[0]>=10000) {
        result[1] = result[0]*0.05;
        result[0] *= 0.95;
    }
    else if(result[0]>=7500){
        result[1]  = result[0]*0.03;
        result[0]*=0.97;
    }
    else if(result[0]>=5000) {
        result[1] = result[0]*0.02;
        result[0]*=0.98;
    }
    
}

void main() {
    int n;
    int result[] = {0, 0};
    printf("Enter the number of items : ");
    scanf("%d", &n);
    int quantities[n];
    int priceList[n];
    printf("-----ENTER PRICE LIST-----\n");
    for(int i = 0;i<n;i++) {
        printf("Enter price of item %d : ", (i+1));
        scanf("%d", priceList+i);
    }
    printf("\n-----ENTER QUANTITY LIST-----\n");
    for(int i = 0;i<n;i++) {
        printf("Enter quantity of item %d : ", (i+1));
        scanf("%d", quantities+i);
    }
    bill(quantities, priceList, n, result);
    printf("\n\nBill before discount = %d\n\n", (result[0]+result[1]));
    printf("Bill after discount = %d\n\n", result[0]);
}