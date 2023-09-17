#include <stdio.h>
#include <string.h>

void memory_dump(char *first, int size){
    char *end = first + size;
    for (; first<end; first++){
        printf("%p:\t%x\n", first, *first);
    }
}

int main(){
    char str[50] = {};

    printf("Please enter your string:\n");
    gets(str);

    char *ptr = &str;
    ptr += strlen(str);


    for(;ptr >= &str; ptr--){
        printf("%c", *ptr);
    }

    return 0;
}