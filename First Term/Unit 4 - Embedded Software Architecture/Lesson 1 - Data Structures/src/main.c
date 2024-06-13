#include "lifo.h"
#include <stdio.h>

#define DISPLAY_ARRAY(array) for (int i = 0; i < 10; i++) printf("%d\n", array[i]);

int arr[10];
LFIO_buffer my_lifo;

int main(){
    int x;

    LIFO_init(&my_lifo, arr, 5);

    for (int i = 0; i < 10; i++)
    {
        LIFO_push(&my_lifo, i);
    }
    
    DISPLAY_ARRAY(arr);

    printf("=====================\n");

    LIFO_pop(&my_lifo, &x);
    DISPLAY_ARRAY(arr);

    return 0;
}
