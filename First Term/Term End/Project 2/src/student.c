#include "student.h"

void student_display(student_t* student){
    printf("Student name: %s %s\n", student->first_name, student->last_name);
    printf("Student id: %d\n", student->id);
    printf("Student gpa: %.2f\n", student->gpa);
    printf("Student courses: ");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ",student->course_ids[i]);
    }
    printf("\n");

}
