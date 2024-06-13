#include "lifo.h"

/** 
 * @brief - Initializes a LIFO_buffer object with the specified address and length.
 * @param base: The address for the base of the LIFO, make sure this address is writable.
 * @param length: The maximum number of 32-bit items to be placed in the LIFO_buffer. 
 */
void LIFO_init(LFIO_buffer * lifo_buffer, unsigned long* base, unsigned long length){
    lifo_buffer->base = base;
    lifo_buffer->head = base;
    lifo_buffer->length = length;
}

/**
 * @brief - Pushes one 32-bit item to the LIFO buffer. Make sure that object is initialized using LIFO_init.
 * @param lifo_buffer: The address of the LIFO_buffer object.
 * @param item: 32-bit item to be pushed.
 */
LIFO_status LIFO_push(LFIO_buffer * lifo_buffer, unsigned long item){

    if (lifo_buffer->base == 0)
    {
        return LIFO_STATUS_NULL;
    }

    if (lifo_buffer->head >= lifo_buffer->base + lifo_buffer->length)
    {
        return LIFO_STATUS_FULL;
    }
    
    *(lifo_buffer->head) = item;
    lifo_buffer->head++;
    return LIFO_STATUS_SUCCESS;
}

/**
 * @brief - Pops one item from the LIFO buffer and writes it to the destination pointer. Make sure that object is initialized using LIFO_init.
 * @param lifo_buffer: The address of the LIFO_buffer object.
 * @param destination: Pointer to the variable passed by reference.
 */
LIFO_status LIFO_pop(LFIO_buffer* lifo_buffer, unsigned long* destination){

    if (lifo_buffer->base == 0)
    {
        return LIFO_STATUS_NULL;
    }
    

    if (lifo_buffer->head == lifo_buffer->base)
    {
        return LIFO_STATUS_EMPTY;
    }
    
    lifo_buffer->head--;
    *destination = lifo_buffer->head;
    return LIFO_STATUS_SUCCESS;

}