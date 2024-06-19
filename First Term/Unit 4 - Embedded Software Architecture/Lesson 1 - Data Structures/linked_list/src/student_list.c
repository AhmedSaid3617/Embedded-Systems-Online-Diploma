#include "student_list.h"
#include <stdio.h>
#include <stdlib.h>

// Add this student to the end of the list.
LIST_STATUS linked_list_append_item(student_t *data, node_t *node)
{
    if (node == NULL)
    {
        return LIST_EMPTY;
    }
    

    // Find the last node.
    while (node->next != NULL)
    {
        node = node->next;
    }

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = *data;
    new_node->next = NULL;

    node->next = new_node;

    return DATA_ADDED;
}

LIST_STATUS linked_list_display(node_t *node)
{

    if (node == NULL)
    {
        return LIST_EMPTY;
    }

    else
    {
        while (1)
        {
            printf("Name: %s\n", node->data.name);
            printf("ID: %d\n", node->data.id);
            printf("Height: %f\n", node->data.height);
            printf("================\n");

            if (node->next == NULL)
            {
                return DATA_SUCCESS;
            }
            else
            {
                node = node->next;
            }
        }
    }
}

LIST_STATUS linked_list_delete_item(int id, node_t *node)
{
    node_t *prev_node = NULL;

    if (node == NULL)
    {
        return LIST_EMPTY;
    }
    

    if (node->data.id == id)
    {
        node_t *to_free = node->next;
        *node = *(node->next);
        free(to_free);
        return DATA_DELETED;
    }

    while (node->next != NULL)
    {
        prev_node = node;
        node = node->next;

        if (node->data.id == id)
        {
            prev_node->next = node->next;
            free(node);
            return DATA_DELETED;
        }
    }

    return DATA_NOT_FOUND;
}

LIST_STATUS linked_list_delete_all(node_t **node)
{

    if (*node == NULL)
    {
        return LIST_EMPTY;
    }
    

    node_t *head_node = *node;
    node_t *prev_node = head_node;
    
    // Set the global head in main to NULL to make it an empty list.
    *node = NULL;

    head_node = head_node->next;

    while (head_node != NULL)
    {
        prev_node = head_node;
        head_node = head_node->next;
        free(prev_node);
    }

    return DATA_DELETED;
}

LIST_STATUS linked_list_get_index(node_t* node, int index, student_t* dest){
    for (int i = 0; i < index; i++)
    {
        if (node->next != NULL)
        {
            node = node->next;
        }
        else {
            return INDEX_OUT_OF_BOUNDS;
        }
    }

    *dest = node->data;
    return DATA_SUCCESS;
    
}

int linked_list_get_length(node_t* node){
    int count = 0;
    while (node != NULL)
    {
        node = node->next;
        count++;
    }
    return count;
}

LIST_STATUS linked_list_get_n_reverse(node_t* node, int n, student_t* dest){
    node_t* first = node;
    node_t* second = node;

    if (node == NULL)
    {
        return LIST_EMPTY;
    }
    

    for (int i = 0; i < n; i++)
    {
        if (node->next != NULL)
        {
            second = second->next;
        }
        else
            return INDEX_OUT_OF_BOUNDS;
    }
    

    while (second != NULL)
    {
        first = first->next;
        second = second->next;
    }
    
    *dest = first->data;
    return DATA_SUCCESS;
}
