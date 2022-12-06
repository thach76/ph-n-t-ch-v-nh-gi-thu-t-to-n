#include <stdio.h>
#include <math.h>

#define MAX_ARRAY 30

int X[MAX_ARRAY];
int cheo1[MAX_ARRAY*2];//chéo xuôi
int cheo2[MAX_ARRAY*2];//chéo ngược
int hang[MAX_ARRAY];//hàng
int N=10;//bàn cờ N*N
int dem = 0;

//in ra màn hình
void printArray(int a[], int start, int end){
    if (start>=end){
        printf("\n");
        return;
    }
    else{
        printf("%d", a[start]);
        printArray(a, start+1, end);
    }
}

void numberSet(int a[], int value, int n){
    for (int i = 0; i<n; i++){
        a[i] = value;
    }
}


void printXepHau(int a[], int n){
    for (int i = 1; i<=n; i++){
        printf("\t\t\t|");
        for (int j = 1; j<=n; j++){
            if (a[i] == j){
                printf("H|");
            }
            else{
                printf(" |");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void writeFile(int a[], int n, char *nameFile){
    FILE *f = fopen(nameFile, "a");
    if (dem == 0){
        fprintf(f, "cac ket qua xep quan hau hop le la: \n");
    }
    dem++;
    fprintf(f, "cach %d: \n", dem);
    for (int i = 1; i<=n; i++){
        fprintf(f, "\t\t\t|");
        for (int j = 1; j<=n; j++){
            if (a[i] == j){
                fprintf(f, "H|");
            }
            else{
                fprintf(f, " |");
            }
        }
        fprintf(f, "\n");
    }
    fprintf(f, "\n");
}

//quay lui
void try(int i){
    //duyệt tất cả khả năng con hậu có thể nhận được
    for (int j = 1; j<=N; j++){
        if (hang[j] == 0 && cheo1[i - j + N] == 0 && cheo2[i + j - 1] == 0){
            X[i] = j;
            hang[j] = 1;
            cheo1[i - j + N] = 1;
            cheo2[i + j - 1] = 1;
            if (i == N){
                //printXepHau(X, N);
                writeFile(X, N, "B8_xephau.txt");
            }
            else{
                try(i + 1);
            }
            //backtrack
            hang[j] = 0;
            cheo1[i - j + N] = 0;
            cheo2[i + j - 1] = 0;
        }
    }
}

int main(){
    numberSet(X, 0, sizeof(X));
    numberSet(hang, 0, sizeof(hang));
    numberSet(cheo1, 0, sizeof(cheo1));
    numberSet(cheo2, 0, sizeof(cheo2));
    //scanf("%d", &N);
    printf("\n");
    try(1);
    return 0;
}

