#include "main.h"

#define MAX_STUDENTS 50

student_t student_db[MAX_STUDENTS];
FIFO_circular_buffer fifo_buffer;
int choice;
char input_name[32];
static int input_id;

int main()
{
    FIFO_buffer_init(&fifo_buffer, student_db, MAX_STUDENTS);
    while (1)
    {
        printf("Choose 1 to add student manually.\n");
        printf("Choose 2 to add student from file.\n");
        printf("Choose 3 to find student by ID.\n");
        printf("Choose 4 to find students by first name.\n");
        printf("Choose 5 to find students in a course.\n");
        printf("Choose 6 to find total number of students. \n");
        printf("Choose 7 to delete a student.\n");
        printf("Choose 8 to update student gpa.\n");
        printf("Choose 9 to show all students.\n");
        printf("Choose 10 to quit.\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("*************************\n");

        switch (choice)
        {
        case 1:
            add_student(&fifo_buffer);
            break;
        case 2:
            get_student_file(&fifo_buffer, "data.txt");
            break;
        case 3:
            find_student(&fifo_buffer);
            break;
        case 4:
            printf("Enter name: ");
            getchar();
            gets(input_name);
            FIFO_find_name(&fifo_buffer, input_name);
            break;
        case 5:
            printf("Enter course id: ");
            scanf("%d", &input_id);
            FIFO_find_students_in_course(&fifo_buffer, input_id);
            break;
        case 6:
            printf("Number of students: %d\n", FIFO_get_count(&fifo_buffer));
            printf("***********************\n");
            break;
        case 7:
            printf("Enter student id: ");
            scanf("%d", &input_id);
            if (FIFO_delete(&fifo_buffer, input_id) == FIFO_SUCCESS)
            {
                printf("Deleted successfully.\n");
            }
            else {
                printf("ID not found.\n");
            }
            printf("********************\n");
            break;
        case 8:
            update_student(&fifo_buffer);
            printf("Updated.\n************************\n");
            break;
        case 9:
            getchar();
            FIFO_display_all(&fifo_buffer);
            break;
        case 10:
            return 0;
            break;
        
        default:
            break;
        }
    }
    
    
}
