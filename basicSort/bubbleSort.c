#include<stdio.h>

void bubbleSort(int *a, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = n-1; j > i; j--){
            if(a[j] < a[j-1]){
                int x = a[j];
                a[j] = a[j-1];
                a[j-1] = x;
            }
        }
    }
}

void printArr(int *a, int n){
    for(int i = 0; i < n; i++){
        printf("%d,  ", a[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("- Sap xep noi bot.\n");
    printf("- Nhap so luong phan tu: ");
    scanf("%d", &n);
    int a[n];
    printf("- Nhap vao cac phan tu:\n");
    for(int i = 0; i < n; i++){
        printf("\t+ a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("- Mang truoc sap xep: ");
    printArr(a, n);
    printf("- Mang sau sap xep: ");
    bubbleSort(a, n);
    printArr(a, n);
    return 0;
}