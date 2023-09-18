#include <stdio.h>
#include <string.h>

struct SEmployee
{
    char m_name[50];
    int m_id;
};


int main(){

    struct SEmployee employee1;
    struct SEmployee employee2;
    struct SEmployee employee3;

    struct SEmployee* ptr_arr[3] = {&employee1, &employee2, &employee3};

    strcpy(ptr_arr[0] -> m_name, "Alex");
    ptr_arr[0] -> m_id = 1002;

    printf("Employee Name: %s\n", employee1.m_name);
    printf("Employee ID: %d\n", employee1.m_id);


    return 0;
}