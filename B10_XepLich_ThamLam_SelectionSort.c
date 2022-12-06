#include <stdio.h>
#include <string.h>

#define MAX_STRING 255

struct LOPHOC{
    int id;
    int start;
    int finish;
};

typedef struct LOPHOC LH;

int readFile(LH a[], char *nameFile){
    FILE *f;
    f = fopen(nameFile, "r");
    if (f == NULL){
        printf("\nloi mo file!");
        return 0;
    }
    int n = 0; //biến chạy
    int num = 0, i = 0;
    while (fscanf(f, "%d", &num) != EOF){
        if (i%3 == 0){
            a[n].id = num;
            i++;
        }
        else if (i%3 == 1){
            a[n].start = num;
            i++;
        }
        else {
            a[n].finish = num;
            i++;
            n++;
        }
    }
    fclose(f);
    return n;
}

void writeFile(LH a[], int n, char *nameFile){
    FILE *f;
    f = fopen(nameFile, "w");
    fprintf(f, "so lop toi uu: %d\n", n);
    for (int i = 0; i<n; i++){
        fprintf(f, "\t%8d%8d%8d\n", a[i].id, a[i].start, a[i].finish);
    }
    fclose(f);
}

void putScreen(LH a[], int n){

    for (int i = 0; i<n; i++){
        printf("%d(%d %d)  ", a[i].id, a[i].start, a[i].finish);
    }
    printf("\n");
}

void swap(LH *x, LH *y){
    LH tg = *x;
    *x = *y;
    *y = tg;
}

//sắp xếp chọn
void selectionSort(LH a[], int n){
    int i, j;
    int iMin, tg;
    for (i = 0; i<n-1; i++){
        iMin = i;
        for (j = i+1; j<n;j++){
            if (a[j].finish < a[iMin].finish){
                iMin = j;
            }
        }
        if (iMin != i){
            swap(&a[iMin], &a[i]);
        }
    }
}

int thamLam(LH C[], int lenC, LH O[]){
    O[0] = C[0];
    int lenO = 1;

    int k = C[0].finish;

    for (int i = 1; i<lenC; i++){
        if (C[i].start > k){
            O[lenO++] = C[i];
            k = C[i].finish;
        }
    }
    return lenO;
}

int main(){
    LH C[MAX_STRING], O[MAX_STRING];
    int lenC = readFile(C, "B10_11_12_input.txt");
    selectionSort(C, lenC);
    printf("cac lop duoc sep lich: %d\n", lenC);
    putScreen(C, lenC);
    int lenO = thamLam(C, lenC, O);
    printf("so lop toi uu: %d\n", lenO);
    putScreen(O, lenO);
    writeFile(C, lenC, "B10_output.txt");
    return 0;
}
