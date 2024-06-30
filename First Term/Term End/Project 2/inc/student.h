#ifndef STUDENT_H
#define STUDENT_H

typedef struct
{
    char first_name[50];
    char last_name[50];
    int id;
    float gpa;
    int course_ids[10];
} student_t ;


#endif