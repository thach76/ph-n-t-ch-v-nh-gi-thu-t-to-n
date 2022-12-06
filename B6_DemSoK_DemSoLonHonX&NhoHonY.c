#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y){
    int tg = *x;
    *x = *y;
    *y = tg;
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

// Hàm tìm kiếm nhị phân sử dụng giải thuật đệ quy
int binarySearch(int arr[], int n, int x) {
  int r = n - 1; // chỉ số phần tử cuối
  int l = 0; // Chỉ số phần tử đầu tiên
  while (r >= l) {
    int mid = l + (r - l) / 2; // Tương đương (l+r)/2 nhưng ưu điểm tránh tràn số khi l,r lớn

    // Nếu arr[mid] = x, trả về chỉ số và kết thúc.
    if (arr[mid] == x){
        while (arr[mid-1] == x){
            mid--;
        }
        return mid;
    }


    // Nếu arr[mid] > x, cập nhật lại right
    if (arr[mid] > x)
      r = mid - 1;
    // Nếu arr[mid] < x, cập nhật lại left
    if (arr[mid] < x)
      l = mid + 1;
  }

  // Nếu không tìm thấy
  return -1;
}


int readFile(int a[], char *nameFile){
    FILE *f;
    f = fopen(nameFile, "r");
    if (f == NULL){
        printf("\nloi mo file!");
        return 0;
    }
    int n = 0; //biến chạy
    while (fscanf(f, "%d", &a[n++]) != EOF){
    }
    return n;
}

void coutFun(int a[], int n){
    int dem1=0,dem2=0;
    int k = 1542,x = 323,y = 3244;
    int index1 = binarySearch(a, n, k);
    if (index1 != -1) // tìm thấy
        for (int i = index1; ;i++){
            if(a[i] == k){
                dem1++;
            }
            else break;
        }
    for(int i=0;i<n;i++)
    {
        if(a[i]>x && a[i]<y)
        {
            dem2++;
        }
    }
    printf("\nfile co %d so bang k\n",dem1);
    printf("file co %d so lon hon x va nho hon y",dem2);
}

//in ra màn hình
void printArray(int a[], int start, int end){
    if (start>=end)
        return;
    else{
        printf("%8d", a[start]);
        printArray(a, start+1, end);
    }
}


int main()
{
    int a[20000];
    char input[255] = "10_000.txt";
    int n = readFile(a, input);
    printf("co %d so\n", n);
    shakerSort(a, n);
    //printArray(a, 0, n);
    coutFun(a, n);
    return 0;
}
