#ifndef LIFO_H
#define LIFO_H

#include <stdio.h>

void func();

typedef struct LFIO_buffer
{
    int * base;
    int * head;
    int length;
};

#endif
