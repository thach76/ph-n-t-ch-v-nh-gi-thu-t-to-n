#include <stdio.h>
#include <conio.h>

void swap(int *x, int *y){
    int tg = *x;
    *x = *y;
    *y = tg;
}

int inpartition(int a[], int low, int high){
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j<high; j++){
        if (a[j] < pivot){
            i++;
            if (i != j){
                swap(&a[i], &a[j]);
            }
        }
    }
    swap(&a[++i], &a[high]);
    return i;
}

//sắp xếp nhanh
void quickSort(int a[], int left, int right){
    if (left < right){
        int index = inpartition(a, left, right);
        quickSort(a, index+1, right);
        quickSort(a, left, index-1);
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
    quickSort(a, 0, n-1);
    printArray(a, 0, n);
    return 0;
}
