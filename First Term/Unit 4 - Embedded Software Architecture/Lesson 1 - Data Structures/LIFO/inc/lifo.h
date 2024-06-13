#ifndef LIFO_H
#define LIFO_H

typedef enum {
    LIFO_STATUS_SUCCESS,
    LIFO_STATUS_FULL,
    LIFO_STATUS_EMPTY,
    LIFO_STATUS_NULL
} LIFO_status;

typedef struct
{
    int * base;
    int * head;
    int length;
} LFIO_buffer;

void LIFO_init(LFIO_buffer * lifo_buffer, unsigned long* base, unsigned long length);
LIFO_status LIFO_push(LFIO_buffer* lifo_buffer, unsigned long item);
LIFO_status LIFO_pop(LFIO_buffer* lifo_buffer, unsigned long* destination);

#endif
