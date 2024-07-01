#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <string.h>
#include "student.h"
#include "fifo.h"

void add_student(FIFO_circular_buffer* fifo_buffer);
void get_student_file(FIFO_circular_buffer* fifo_buffer, char* file_path);
FIFO_status update_student(FIFO_circular_buffer* fifo_buffer);
void find_student(FIFO_circular_buffer *fifo_buffer);

#endif