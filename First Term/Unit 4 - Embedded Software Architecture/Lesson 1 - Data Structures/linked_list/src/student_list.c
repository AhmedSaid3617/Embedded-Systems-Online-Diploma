#include "student_list.h"
#include <stdio.h>
#include <stdlib.h>

// Add this student to the end of the list.
DATA_STATUS linked_list_append_item(student_t *data, node_t *node)
{
    if (node == NULL)
    {
        return DATA_EMPTY_LIST;
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

DATA_STATUS linked_list_display(node_t *node)
{

    if (node == NULL)
    {
        return DATA_EMPTY_LIST;
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

DATA_STATUS linked_list_delete_item(int id, node_t *node)
{
    node_t *prev_node = NULL;

    if (node == NULL)
    {
        return DATA_EMPTY_LIST;
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

DATA_STATUS linked_list_delete_all(node_t **node)
{

    if (*node == NULL)
    {
        return DATA_EMPTY_LIST;
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
