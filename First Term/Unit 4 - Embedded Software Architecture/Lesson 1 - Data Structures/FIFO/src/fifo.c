#include "fifo.h"
#include <stdio.h>

void FIFO_buffer_init(FIFO_circular_buffer* fifo_buffer, unsigned char* base, unsigned int length){
    fifo_buffer->base = base;
    fifo_buffer->head = base;
    fifo_buffer->tail = base;
    fifo_buffer->length = length;
    fifo_buffer->is_full = 0;
}

FIFO_STATUS FIFO_enqueue(FIFO_circular_buffer* fifo_buffer, unsigned char item){
    if (fifo_buffer->base == 0)
    {
        return FIFO_NULL;
    }
    
    if (fifo_buffer->is_full)
    {
        return FIFO_FULL;
    }

    *(fifo_buffer->head) = item;

    if (fifo_buffer->head == fifo_buffer->base + fifo_buffer->length - 1)
    {
        fifo_buffer->head = fifo_buffer->base;
    }
    else {
        fifo_buffer->head++;
    }

    if (fifo_buffer->head == fifo_buffer->base)
    {
        fifo_buffer->is_full = 1;
    }
    
    return FIFO_SUCCESS;
}

FIFO_STATUS FIFO_dequeue(FIFO_circular_buffer* fifo_buffer, unsigned char* destination){
    if (fifo_buffer->base == 0)
    {
        return FIFO_NULL;
    }
    
    if (!fifo_buffer->is_full && (fifo_buffer->tail == fifo_buffer->head))
    {
        return FIFO_EMPTY;
    }

    *destination = *(fifo_buffer->tail);

    if (fifo_buffer->tail == fifo_buffer->base + fifo_buffer->length - 1)
    {
        fifo_buffer->tail = fifo_buffer->base;
    }
    else {
        fifo_buffer->tail++;
    }
    
    fifo_buffer->is_full = 0;

    return FIFO_SUCCESS;
}

