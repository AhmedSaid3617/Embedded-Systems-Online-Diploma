#include <stdio.h>
#include <string.h>

int main(){

    char input[100] = {};
    char output[100] = {};
    printf("Enter string: ");
    gets(input);
    char length = strlen(input);

    for (int i=0; i<length; i++){
        output[length-i-1] = input[i];
    }
    printf("Reversed string is: %s", output);

    return 0;
}