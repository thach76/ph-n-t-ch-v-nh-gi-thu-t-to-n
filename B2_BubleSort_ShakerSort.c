#include <stdio.h>
#include <conio.h>

void swap(int *x, int *y){
    int tg = *x;
    *x = *y;
    *y = tg;
}

void bubleSort(int a[], int n){
    int i, j;
    for (i = 0; i<n; i++){
        for (j = n - i - 1; j> 0; j--){
            if (a[j] < a[j-1]){
                swap(&a[j], &a[j-1]);
            }
        }
    }
}

void shakerSort(int a[], int n){
    int i, j, k;
    int left = 0;
    int right = n-1;
    while (left<right){
        for (i = left; i<right; i++){
            if (a[i] > a[i+1]){
                swap(&a[i], &a[i+1]);
                k = i;
            }
        }
        right = k;
        for (i = right; i>left; i--){
            if (a[i] < a[i-1]){
                swap(&a[i], &a[i-1]);
                k = i;
            }
        }
        left = k;
    }
}

//in ra màn hình
void printArray(int a[], int i, int n){
    if (i>=n)
        return;
    else{
        printf("%8d", a[i]);
        printArray(a, i+1, n);
    }
}

int main(){
    int a[] = {4, 5, 2, 10, 2, 8, 9, 3, 12, 0};
    int n = sizeof(a)/sizeof(a[0]);
    //bubleSort(a, n);
    shakerSort(a, n);
    printArray(a, 0, n);
    return 0;
}
