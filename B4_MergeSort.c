#include <stdio.h>
#include <conio.h>

int Left[1000], Right[1000];

void swap(int *x, int *y){
    int tg = *x;
    *x = *y;
    *y = tg;
}

void merge(int a[], int left, int mid, int right){
    int i, j, k;  //biến chạy
    int n1 = mid - left + 1;//số phần tử từ left đến mid
    int n2 = right - mid;  //số phần tử từ mid ra right

    for (i = 0; i < n1; i++)
        Left[i] = a[left + i];  //đưa toàn bộ số phần từ bên trái mid và Left
    for (j = 0; j < n2; j++)
        Right[j] = a[mid + 1 + j];  //đưa toàn bộ số phần từ bên phải mid và Right

    i = 0; // chỉ số ban đầu của mảng Left
    j = 0; // chỉ số ban đầu của mảng Right
    k = left; // chỉ số ban đầu của mảng merge
    while (i < n1 && j < n2) {  //thoát khi i >= n1 hoặc j >= n2
        if (Left[i] <= Right[j]) {
            a[k] = Left[i];
            i++;
        }
        else {
            a[k] = Right[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        a[k] = Left[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        a[k] = Right[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int left, int right){
    if (left< right){
        int mid = (left + right)/2;
        // sắp xếp nửa thứ nhất và nửa thứ 2
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        merge(a, left, mid, right);
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
    mergeSort(a, 0, n-1);
    printArray(a, 0, n);
    return 0;
}
