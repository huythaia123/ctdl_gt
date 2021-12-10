#include<stdio.h>

void selectSort(int *a, int n){
    int m, temp;
    for(int i = 0; i < n-1; i++){
        m = i;
        for(int j = i+1; j < n; j++){
            if(a[j] < a[m]){
                m = j;
            }
        }
        if(m != i){
            temp = a[i];
            a[i] = a[m];
            a[m] = temp;
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
    printf("- Sap xep luc chon.\n");
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
    selectSort(a, n);
    printArr(a, n);
}