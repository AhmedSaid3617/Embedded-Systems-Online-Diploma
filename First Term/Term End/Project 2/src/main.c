#include "main.h"

#define MAX_STUDENTS 50

student_t student_db[MAX_STUDENTS];
FIFO_circular_buffer fifo_buffer;
student_t input_student;
student_t student2;

int main()
{
    FIFO_buffer_init(&fifo_buffer, student_db, MAX_STUDENTS);

    strcpy(student2.first_name, "Ahmed");
    strcpy(student2.last_name, "Said");
    student2.id = 2101546;
    student2.gpa = 3.28;
    student2.course_count = 6;
    for (int i = 0; i < 6; i++)
    {
        student2.course_ids[i] = i + 1;
    }

    FIFO_enqueue(&fifo_buffer, &student2);
    FIFO_enqueue(&fifo_buffer, &student2);
    add_student();
    FIFO_display_all(&fifo_buffer);
}

void add_student()
{
    printf("************************\n");
    printf("Enter first name: ");
    gets(&input_student.first_name);

    printf("Enter last name: ");
    gets(&input_student.last_name);

    printf("Enter student id: ");
    scanf("%d", &input_student.id);

    while (FIFO_search(&fifo_buffer, input_student.id) != NULL || input_student.id == 0)
    {
        if (FIFO_search(&fifo_buffer, input_student.id) != NULL)
        {
            printf("ID already exists, please enter another one.\n");
        }
        else if (input_student.id == 0)
        {
            printf("ID cannot be 0, please enter another one.\n");
        }

        printf("Enter student id: ");
        scanf("%d", &input_student.id);
    }

    printf("Enter student gpa: ");
    scanf("%f", &input_student.gpa);
    printf("\n");

    printf("Enter number of courses (0 - 10): ");
    scanf("%d", &input_student.course_count);

    for (int i = 0; i < input_student.course_count; i++)
    {
        printf("Course id: ");
        scanf("%d", &input_student.course_ids[i]);
    }

    FIFO_enqueue(&fifo_buffer, &input_student);
    printf("************************\n");
}