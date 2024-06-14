#include "fifo.h"
#include <stdio.h>

#define DISPLAY_ARRAY(array)     \
    for (int i = 0; i < 10; i++) \
    printf("%d\n", array[i])

FIFO_circular_buffer my_fifo;
char arr[10];

int main()
{
    char x;
    FIFO_buffer_init(&my_fifo, arr, 10);

    for (int i = 0; i < 15; i++)
    {
        if (FIFO_enqueue(&my_fifo, i + 1) != FIFO_SUCCESS)
        {
            printf("Insuccessful\n");
        }
        
    }

    for (int i = 0; i < 12; i++)
    {
        if (FIFO_dequeue(&my_fifo, &x) != FIFO_SUCCESS)
        {
            printf("Insuccessful\n");
        }
    } 

    DISPLAY_ARRAY(arr);

    printf("\n================\n%d", x);
}