#include "fifo.h"
#include <stdio.h>

void FIFO_buffer_init(FIFO_circular_buffer *fifo_buffer, student_t *base, unsigned int length)
{
    fifo_buffer->base = base;
    fifo_buffer->head = base;
    fifo_buffer->tail = base;
    fifo_buffer->length = length;
    fifo_buffer->is_full = 0;
}

FIFO_STATUS FIFO_enqueue(FIFO_circular_buffer *fifo_buffer, student_t* item)
{
    if (fifo_buffer->base == 0)
    {
        return FIFO_NULL;
    }

    if (fifo_buffer->is_full)
    {
        return FIFO_FULL;
    }

    *(fifo_buffer->head) = *item;

    if (fifo_buffer->head == fifo_buffer->base + fifo_buffer->length - 1)
    {
        fifo_buffer->head = fifo_buffer->base;
    }
    else
    {
        fifo_buffer->head++;
    }

    if (fifo_buffer->head == fifo_buffer->base)
    {
        fifo_buffer->is_full = 1;
    }

    return FIFO_SUCCESS;
}

FIFO_STATUS FIFO_dequeue(FIFO_circular_buffer *fifo_buffer, student_t *destination)
{
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
    else
    {
        fifo_buffer->tail++;
    }

    fifo_buffer->is_full = 0;

    return FIFO_SUCCESS;
}

student_t* FIFO_search(FIFO_circular_buffer *fifo_buffer, int id)
{
    student_t *index = fifo_buffer->tail;
    while (index != fifo_buffer->head)
    {
        // Return address if found.
        if (index->id == id)
        {
            return index;
        }
        // Increment index.
        if (index == fifo_buffer->base + fifo_buffer->length - 1)
        {
            index = fifo_buffer->base;
        }
        else
        {
            index++;
        }
    }

    return NULL;
}

void FIFO_display_all(FIFO_circular_buffer *fifo_buffer){
    student_t *index = fifo_buffer->tail;
    while (index != fifo_buffer->head)
    {
        student_display(index);
        printf("======================\n");
        // Increment index.
        if (index == fifo_buffer->base + fifo_buffer->length - 1)
        {
            index = fifo_buffer->base;
        }
        else
        {
            index++;
        }
    }
    
}
