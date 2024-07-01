#include "io.h"

student_t input_student;
char string_buffer[100];

void add_student(FIFO_circular_buffer* fifo_buffer)
{
    printf("************************\n");
    printf("Enter first name: ");
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
    printf("\n");

    printf("Enter 4 course IDs: ");
    scanf("%d %d %d %d", &input_student.course_ids[0], &input_student.course_ids[1], &input_student.course_ids[2], &input_student.course_ids[3]);

    FIFO_enqueue(fifo_buffer, &input_student);
    printf("************************\n");
}

void get_student_file(FIFO_circular_buffer* fifo_buffer, char* file_path){
    FILE* file_pointer = fopen("data.txt", "r");

    while (fgets(string_buffer, 100, file_pointer));
    {
        sscanf(string_buffer, "%d %s %s %f %d %d %d %d", &input_student.id, &input_student.first_name,\
        &input_student.last_name, &input_student.gpa, &input_student.course_ids[0],\
        &input_student.course_ids[1], &input_student.course_ids[2], &input_student.course_ids[3]);

        if (FIFO_search(fifo_buffer, input_student.id))
        {
            printf("ID %d for student %s %s already exists\n", input_student.id, input_student.first_name, input_student.last_name);
            printf("Entry discarded\n");
        }
        else{
            FIFO_enqueue(fifo_buffer, &input_student);
        }
        
    }
    fclose(file_pointer);
}
