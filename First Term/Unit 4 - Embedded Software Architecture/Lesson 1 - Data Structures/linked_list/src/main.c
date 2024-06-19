#include "student_list.h"
#include "string.h"
#include <stdio.h>

student_t student1;
student_t student2;
node_t first_node;
node_t* head = &first_node;

student_t student_input;
int id_to_delete = -1;

char quit = 0;

void get_command();
void read_student(student_t* student);
void delete_student();

int main(){
    student1.id = 10;
    student1.height = 170;
    strcpy(student1.name, "Ahmed Said");

    student2.id = 20;
    student2.height = 165;
    strcpy(student2.name, "Mohamed");

    first_node.data = student1;

    linked_list_append_item(&student2, head);
    linked_list_display(head);

    

    while (!quit)
    {
        get_command();
    } 
    
    
    return 0;
}

void get_command(){
    char input = -1;
    printf("===================\n");
    printf("1 - Add a student.\n2 - Display students.\n3 - Delete a student.\n4 - Delete all.\n5 - Quit.\n");
    scanf("%d", &input);
    switch (input)
    {
    case 1:
        read_student(&student_input);
        if (linked_list_append_item(&student_input, head) == DATA_EMPTY_LIST)
        {
            printf("List is empty\n");
        }
        else
        {
            printf("Added Successfully\n");
        }
        
        break;

    case 2:
        printf("===================\n");
        if (linked_list_display(head) == DATA_EMPTY_LIST)
        {
            printf("List is empty.\n");
        }
        break;

    case 3:
        delete_student();
        break;

    case 4:
        if (linked_list_delete_all(&head) == DATA_DELETED)
        {
            printf("Successfully deleted.\n");
        }
        else{
            printf("List is empty\n");
        }
        break;  

    case 5:
        quit = 1;
        break;

    default:
        printf("Invalid input.\n");
        break;
    }
}

void read_student(student_t* student){
    printf("Enter name: ");
    getchar();
    gets(student->name); 

    printf("Enter id: ");
    scanf_s("\n%d", &student->id);

    printf("Enter height: ");
    scanf_s("\n%f", &student->height);
}

void delete_student(){
    printf("Enter student id to delete: ");
    scanf("%d", &id_to_delete);
    int status = linked_list_delete_item(id_to_delete, head);

    if (status == DATA_DELETED)
    {
        printf("Deleted successfully.\n");
    }
    else if (status == DATA_EMPTY_LIST)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("No student with this id.\n");
    }
    
}
