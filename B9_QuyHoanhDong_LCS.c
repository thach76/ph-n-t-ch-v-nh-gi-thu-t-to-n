#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_STRING 255
#define Max(a, b) a > b ? a : b

char con[MAX_STRING];

void readFile(char a[][MAX_STRING], char *nameFile){
    FILE *f;
    f = fopen(nameFile, "r");
    if (f == NULL){
        printf("\nloi mo file!");
        return;
    }
    int n = 0; //biến chạy
    while (fscanf(f, "%s", &a[n++]) != EOF){
    }
    fclose(f);
}

void writeFile(char a[][MAX_STRING], char *nameFile){
    FILE *f;
    f = fopen(nameFile, "w");
    fprintf(f, "LCS:\n");
    fprintf(f, "%s\n", a[0]);
    fprintf(f, "%s\n", a[1]);
    fprintf(f, "%d\n", strlen(con));
    fprintf(f, "%s\n", con);
    fclose(f);
}

void putScreen(char a[][MAX_STRING]){
    printf("LCS:\n");
    printf("%s\n", a[0]);
    printf("%s\n", a[1]);
    printf("%d\n", strlen(con));
    printf("%s\n", con);
}

void LCS(char *s1, char *s2){
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int i,j,indexCon;

    int C[MAX_STRING][MAX_STRING];

    for (i = 0; i<=len1; i++) C[i][0] = 0;
    for (i = 0; i<=len2; i++) C[0][i] = 0;

    for (i = 1; i<=len1; i++)
        for (j = 1; j<=len2; j++){
            if (s1[i-1] == s2[j-1])
                C[i][j] = C[i-1][j-1] + 1;
            else
                C[i][j] = Max(C[i-1][j], C[i][j-1]);
        }

    indexCon = C[len1][len2];

    con[indexCon] = '\0';

    i = len1, j = len2;
    while (i >= 0 && j >= 0){
        if (s1[i-1] == s2[j-1]){
            indexCon--;
            con[indexCon] = s1[i-1];
            i--;
            j--;
        }
        else if (C[i-1][j] > C[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
}

int main(){
    char a[100][MAX_STRING];
    char nameFileIn[MAX_STRING] = "B9_input.txt";
    char nameFileOut[MAX_STRING]= "B9_output.txt";
    readFile(a, nameFileIn);
    LCS(a[0], a[1]);
    writeFile(a, nameFileOut);
    putScreen(a);
    return 0;
}
