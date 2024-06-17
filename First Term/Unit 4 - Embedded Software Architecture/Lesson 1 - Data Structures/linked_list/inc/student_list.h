#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

typedef struct
{
    char name[20];
    int id;
    float height;

} student_t;

typedef struct 
{
    student_t student;
    node_t* next;
} node_t;

#endif