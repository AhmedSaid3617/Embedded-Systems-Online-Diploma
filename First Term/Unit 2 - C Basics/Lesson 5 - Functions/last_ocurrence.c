#include <stdio.h>

int last_occurrence(int* arr, int size, int num){
    for (int i=size-1; i>=0; i--){
        if (arr[i] == num){
            return i;
        }
    }
    return -1;
}

int main() {
    int x[100] = {1, 2, 3, 4, 5};
    printf("%d", last_occurrence(x, 5, 3));
    return 0;
}