#include <stdio.h>

int main(){
    char a[100][100];
    char columns;
    char rows;
    printf("Enter number of rows and columns: ");
    scanf("%d", &rows);

    scanf("%d", &columns);


    printf("\nEnter elements of matrix.\n");
    for (int i=0; i<rows; i++){
        for (int j=0; j<columns; j++){
            printf("Enter a%d%d: ", i+1, j+1);
            scanf("%f", &a[i][j]);
        }
    }

    for (int i=0; i<rows; i++){
        for (int j=0; j<columns; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("==========\n");

    int b[3][3];

    for (int i=0; i<columns; i++){
        for (int j=0; j<rows; j++){
            b[i][j] = a[j][i];
        }
    }

    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}