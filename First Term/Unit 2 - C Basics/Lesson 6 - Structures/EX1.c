#include <stdio.h>

struct SStudent
{
    char m_name[50];
    int m_rollnum;
    float m_marks;
};


int main(){
    struct SStudent new_student;
    printf("Entering information of student\n");
    printf("Enter name: ");
    gets(new_student.m_name);

    printf("Enter roll number: ");
    scanf("%d", &new_student.m_rollnum);

    printf("Enter marks: ");
    scanf("%f", &new_student.m_marks);

    printf("\nDisplaying data\n");

    printf("Name: %s\n", new_student.m_name);
    printf("Roll number: %d\n", new_student.m_rollnum);
    printf("Marks: %f\n", new_student.m_marks);


    return 0;
}