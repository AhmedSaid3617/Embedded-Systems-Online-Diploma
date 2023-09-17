#include <stdio.h>

int main(){
    int m = 29;
    int *ab = &m;
    printf("Address of m: 0x%x\n", ab);
    printf("Value of m: %d\n", *ab);

    printf("Assign m to 34.\n");
    m = 34;
    printf("Address of m: 0x%x\n", ab);
    printf("Value of m: %d\n", *ab);

    printf("Assign ab to 7.\n");

    *ab = 7;
    printf("Address of m: 0x%x\n", ab);
    printf("Value of m: %d\n", *ab);

    return 0;
}