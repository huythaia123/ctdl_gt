#include<stdio.h>

void insertSort(int *a, int n){
    int key, j;
    for(int i = 1; i < n; i++){
        key = a[i];
        j = i - 1;
        while(key < a[j] && j >= 0){
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = key;
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
    printf("- Sap xep chen.\n");
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
    insertSort(a, n);
    printArr(a, n);
    return 0;
}