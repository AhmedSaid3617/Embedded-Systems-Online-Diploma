#include "student_list.h"
#include <stdio.h>
#include <stdlib.h>

// Add this student to the end of the list.
void linked_list_append_item(student_t *data, node_t *node)
{

    // Find the last node.
    while (node->next != NULL)
    {
        node = node->next;
    }

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = *data;
    new_node->next = NULL;

    node->next = new_node;
}

void linked_list_display(node_t *node)
{

    if (node->data.id == 0)
    {
        printf("List is empty.\n");
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
                break;
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

void linked_list_delete_all(node_t *node)
{
    node_t *prev_node = node;
    node = node->next;
    prev_node->data.height = 0;
    prev_node->data.id = 0;

    while (node != NULL)
    {
        prev_node = node;
        node = node->next;
        free(prev_node);
    }
}
