#include <stdio.h>

struct SStudent
{
    char m_name[50];
    int m_rollnum;
    float m_marks;
};



int main(){

    struct SStudent new_student;
    char name[50];
    struct SStudent students[3];
    for (int i=0; i<3; i++){
        printf("For student roll number %d\n", i+1);
        students[i].m_rollnum = i+1;

        printf("Enter name: ");
        gets(students[i].m_name);

        printf("Enter marks: ");
        scanf("%f", &students[i].m_marks);
        getchar();
    }

    printf("\nDisplaying data\n\n");
    for (int i=0; i<3; i++){
        printf("Displaying student %d\n", i+1);
        printf("Name: %s\n", students[i].m_name);
        printf("Roll number: %d\n", students[i].m_rollnum);
        printf("Marks: %f\n\n", students[i].m_marks);
        
    
    }
    
    return 0;
    
}