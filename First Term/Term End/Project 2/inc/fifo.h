#ifndef FIFO_H
#define FIFO_H

#include <stdio.h>
#include <string.h>
#include "student.h"

typedef struct
{
    student_t* base;
    student_t* head;
    student_t* tail;
    unsigned int length;
    char is_full;
} FIFO_circular_buffer;

typedef enum {
    FIFO_SUCCESS,
    FIFO_FULL,
    FIFO_EMPTY,
    FIFO_NULL,
    FIFO_NOT_FOUND,
    FIFO_INVALID
} FIFO_status;

void FIFO_buffer_init(FIFO_circular_buffer* fifo_buffer, student_t* base, unsigned int length);

FIFO_status FIFO_enqueue(FIFO_circular_buffer *fifo_buffer, student_t* item);

FIFO_status FIFO_dequeue(FIFO_circular_buffer* fifo_buffer, student_t* destination);

student_t* FIFO_search(FIFO_circular_buffer *fifo_buffer, int id);

void FIFO_display_all(FIFO_circular_buffer *fifo_buffer);

void FIFO_find_name(FIFO_circular_buffer *fifo_buffer, char* name);

void FIFO_find_students_in_course(FIFO_circular_buffer *fifo_buffer, int course_id);

FIFO_status FIFO_delete(FIFO_circular_buffer *fifo_buffer, int id);

#endif