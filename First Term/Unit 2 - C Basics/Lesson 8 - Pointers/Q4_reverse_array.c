#include <stdio.h>

int main(){
    int arr[15] = {};
    int size;

    printf("Please enter number of items (max 15): ");
    scanf("%d", &size);
    

    for (int i=0; i<size; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int *ptr = arr;
    ptr += size-1;

    printf("Elements in reverse order:\n");
    for(;ptr >= arr; ptr--){
        printf("%d\n", *ptr);
    }

    return 0;
}