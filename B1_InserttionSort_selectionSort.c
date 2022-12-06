#include <stdio.h>
#include <conio.h>

//sắp sếp chèn
void inserttionSort(int a[], int n){
    int i, j, key;
    for (i = 1; i<n; i++){
        key = a[i];
        j = i-1;
        //số nhỏ nhất sẽ đưa lên đầu
        while (j>=0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

//sắp xếp chọn
void selectionSort(int a[], int n){
    int i, j, iMin, tg;
    for (i = 0; i<n-1; i++){
        iMin = i;
        for (j = i+1; j<n;j++){
            if (a[j] < a[iMin]){
                iMin = j;
            }
        }
        if (iMin != i){
            tg = a[iMin];
            a[iMin] = a[i];
            a[i] = tg;
        }
    }
}

int khuTrung(int a[], int n){
    int end = 0;
    for (int i = 0; i<n; i++){
        if (a[i] != a[end]){
            end++;
            a[end] = a[i];
        }
    }
    return end + 1;
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
    selectionSort(a, n);
    //inserttionSort(a, n);
    int n2 = khuTrung(a, n);
    printArray(a, 0, n2);
    return 0;
}
