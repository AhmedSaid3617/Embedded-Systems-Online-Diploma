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
    LIST_EMPTY,
    DATA_ADDED,
    DATA_SUCCESS,
    INDEX_OUT_OF_BOUNDS
} LIST_STATUS;

typedef struct node_s node_t;

LIST_STATUS linked_list_append_item(student_t* data, node_t* node);

LIST_STATUS linked_list_display(node_t* node);

LIST_STATUS linked_list_delete_item(int id, node_t* node);

LIST_STATUS linked_list_delete_all(node_t **node);

LIST_STATUS linked_list_get_index(node_t* node, int index, student_t* dest);

int linked_list_get_length(node_t* node);

LIST_STATUS linked_list_get_n_reverse(node_t* node, int n, student_t* dest);


#endif