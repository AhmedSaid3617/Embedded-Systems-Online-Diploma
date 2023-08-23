#include <stdio.h>
#include <string.h>

int fourth_last_dig(int number){

    return ((number >> 3)%2 == 1);
}

void swap(int* A, int* B, int a_size, int b_size){
    int min = (a_size > b_size)? b_size: a_size;
    int temp;
    for (int i=0; i <min; i++){
        temp = A[i];
        A[i] = B[i];
        B[i] = temp;
    }
}

int power_of_3(int num){
    if (num ==3)
        return 0;
    else if(num == 0)
        return 1;
    return power_of_3(num/3);
}

int clear_bit(int num, int pos){
    return num &= ~(1<<pos);
}

int is_same(char* input){
    char username[6] = "hello";
    return (strcmp(input, username) == 0)? 1:0;
}

int main(){
    printf("%d", is_same("56"));
    printf("%p", main);
    return 0;
}