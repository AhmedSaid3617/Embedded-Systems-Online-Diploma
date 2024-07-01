#include "io.h"

student_t input_student;
student_t *displayed_student;
char string_buffer[100];
static int input_id;

void add_student(FIFO_circular_buffer *fifo_buffer)
{
    printf("************************\n");
    printf("Enter first name: ");
    getchar();
    gets(&input_student.first_name);

    printf("Enter last name: ");
    gets(&input_student.last_name);

    printf("Enter student id: ");
    scanf("%d", &input_student.id);

    while (FIFO_search(fifo_buffer, input_student.id) != NULL || input_student.id == 0)
    {
        if (FIFO_search(fifo_buffer, input_student.id) != NULL)
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

    printf("Enter 4 course IDs: ");
    scanf("%d %d %d %d", &input_student.course_ids[0], &input_student.course_ids[1], &input_student.course_ids[2], &input_student.course_ids[3]);

    FIFO_enqueue(fifo_buffer, &input_student);
    printf("************************\n");
}

FIFO_status update_student(FIFO_circular_buffer *fifo_buffer)
{
    int id;
    printf("Enter student id: ");
    scanf("%d", &id);
    if (id == 0)
    {
        printf("Id cannot be zero.\n");
        return FIFO_INVALID;
    }

    student_t *student = FIFO_search(fifo_buffer, id);
    if (student != NULL)
    {
        printf("Enter new gpa: ");
        scanf("%f", &student->gpa);
        return FIFO_SUCCESS;
    }
    else
    {
        printf("No student with this ID.\n");
        return FIFO_NOT_FOUND;
    }
}

void get_student_file(FIFO_circular_buffer *fifo_buffer, char *file_path)
{
    FILE *file_pointer = fopen("data.txt", "r");

    while (fgets(string_buffer, 100, file_pointer))
    {
        sscanf(string_buffer, "%d %s %s %f %d %d %d %d", &input_student.id, &input_student.first_name,
               &input_student.last_name, &input_student.gpa, &input_student.course_ids[0],
               &input_student.course_ids[1], &input_student.course_ids[2], &input_student.course_ids[3]);

        if (FIFO_search(fifo_buffer, input_student.id))
        {
            printf("ID %d for student %s %s already exists\n", input_student.id, input_student.first_name, input_student.last_name);
            printf("Entry discarded\n");
        }
        else
        {
            FIFO_enqueue(fifo_buffer, &input_student);
        }
    }
    fclose(file_pointer);
}

void find_student(FIFO_circular_buffer *fifo_buffer)
{
    printf("Enter ID: ");
    scanf("%d", &input_id);
    displayed_student = FIFO_search(fifo_buffer, input_id);
    if (displayed_student)
    {
        printf("*************************\n");
        student_display(displayed_student);
        printf("*************************\n");
    }
    else
    {
        printf("No student with this ID.\n");
    }
}
