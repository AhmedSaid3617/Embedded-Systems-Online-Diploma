#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
typedef struct
{
    char first_name[50];
    char last_name[50];
    int id;
    float gpa;
    int course_ids[10];
    unsigned char course_count;
} student_t ;

void student_display(student_t* student);

#endif