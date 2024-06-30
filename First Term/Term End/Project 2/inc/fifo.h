#ifndef FIFO_H
#define FIFO_H

#include "student.h"

typedef struct
{
    student_t* base;
    unsigned char* head;
    unsigned char* tail;
    unsigned int length;
    char is_full;
} FIFO_circular_buffer;

typedef enum {
    FIFO_SUCCESS,
    FIFO_FULL,
    FIFO_EMPTY,
    FIFO_NULL
} FIFO_STATUS;

void FIFO_buffer_init(FIFO_circular_buffer* fifo_buffer, student_t* base, unsigned int length);

FIFO_STATUS FIFO_enqueue(FIFO_circular_buffer* fifo_buffer, student_t item);

FIFO_STATUS FIFO_dequeue(FIFO_circular_buffer* fifo_buffer, student_t* destination);

#endif