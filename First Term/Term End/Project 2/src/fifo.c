#include "fifo.h"

void FIFO_buffer_init(FIFO_circular_buffer *fifo_buffer, student_t *base, unsigned int length)
{
    fifo_buffer->base = base;
    fifo_buffer->head = base;
    fifo_buffer->tail = base;
    fifo_buffer->length = length;
    fifo_buffer->is_full = 0;
}

FIFO_status FIFO_enqueue(FIFO_circular_buffer *fifo_buffer, student_t *item)
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

FIFO_status FIFO_dequeue(FIFO_circular_buffer *fifo_buffer, student_t *destination)
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

FIFO_status FIFO_delete(FIFO_circular_buffer *fifo_buffer, int id)
{
    student_t *index = FIFO_search(fifo_buffer, id);
    student_t *next_index = NULL;
    if (index != NULL)
    {
        while (index != fifo_buffer->head)
        {
            if (index == fifo_buffer->base + fifo_buffer->length - 1)
            {
                next_index = fifo_buffer->base;
            }
            else
            {
                next_index = index+1;
            }

            *index = *next_index;
            index = next_index;
        }
        fifo_buffer->head--;
        return FIFO_SUCCESS;
    }
    return FIFO_NOT_FOUND;
}

student_t *FIFO_search(FIFO_circular_buffer *fifo_buffer, int id)
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

void FIFO_display_all(FIFO_circular_buffer *fifo_buffer)
{
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

void FIFO_find_name(FIFO_circular_buffer *fifo_buffer, char *name)
{
    student_t *index = fifo_buffer->tail;
    int student_count = 0;
    printf("*****************************\n");
    while (index != fifo_buffer->head)
    {
        // Return address if found.
        if (strcmp(index->first_name, name) == 0)
        {
            student_display(index);
            printf("====================\n");
            student_count++;
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
    if (student_count == 0)
    {
        printf("No students with this name.\n");
    }
    printf("*****************************\n");
}

void FIFO_find_students_in_course(FIFO_circular_buffer *fifo_buffer, int course_id)
{
    student_t *index = fifo_buffer->tail;
    int student_count = 0;
    printf("*****************************\n");
    while (index != fifo_buffer->head)
    {
        // Return address if found.
        for (int i = 0; i < 4; i++)
        {
            if (index->course_ids[i] == course_id)
            {
                student_display(index);
                printf("====================\n");
                student_count++;
                break;
            }
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

    if (student_count == 0)
    {
        printf("No students with this course.\n");
    }
    printf("*****************************\n");
}
