#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

typedef struct
{
    char name[20];
    int id;
    float height;

} student_t;

struct node_s
{
    student_t data;
    struct node_s* next;
};

typedef enum {
    DATA_NOT_FOUND,
    DATA_DELETED,
    DATA_EMPTY_LIST,
    DATA_ADDED,
    DATA_SUCCESS
} DATA_STATUS;

typedef struct node_s node_t;

DATA_STATUS linked_list_append_item(student_t* data, node_t* node);

DATA_STATUS linked_list_display(node_t* node);

DATA_STATUS linked_list_delete_item(int id, node_t* node);

DATA_STATUS linked_list_delete_all(node_t **node);


#endif