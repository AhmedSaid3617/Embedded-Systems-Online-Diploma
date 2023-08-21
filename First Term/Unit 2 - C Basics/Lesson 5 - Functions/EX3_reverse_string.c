#include <stdio.h>
#include <string.h>

char* reverse_string(char* string, int n){
    static char output[100];
    static char index = 0;
    n--;
    if(n == -1){
        return output;
    }

    output[index] = string[n];
    index++;
    reverse_string(string, n);
}

int main(){
    printf("Enter a sentence: ");
    char input[100];
    gets(input);
    printf(reverse_string(input, strlen(input)));
    return 0;
}