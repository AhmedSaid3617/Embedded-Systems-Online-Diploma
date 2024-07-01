#include "main.h"

#define MAX_STUDENTS 50

student_t student_db[MAX_STUDENTS];
FIFO_circular_buffer fifo_buffer;
student_t student2;
FILE  *file_ptr;

char string[20];

int main()
{
    FIFO_buffer_init(&fifo_buffer, student_db, MAX_STUDENTS);

    strcpy(student2.first_name, "Ahmed");
    strcpy(student2.last_name, "Said");
    student2.id = 2101546;
    student2.gpa = 3.28;
    for (int i = 0; i < 6; i++)
    {
        student2.course_ids[i] = i + 1;
    }

    FIFO_enqueue(&fifo_buffer, &student2);

    //get_student_file(&fifo_buffer, "data.txt");
    update_student(&fifo_buffer);

    FIFO_display_all(&fifo_buffer);
}
