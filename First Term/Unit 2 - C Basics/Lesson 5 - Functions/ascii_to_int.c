#include <stdio.h>
#include <string.h>
#include <math.h>

int ascii_to_int(char* string){
    int size = strlen(string);
    int result = 0;

    for (int i=size-1, n=0; i>=0; i--, n++){
        result += (string[i]-48) * pow(10, n);
    }

    return result;
}

int main(){

    printf("%d\n", ascii_to_int("12345"));
    printf("%d", pow(234, 0));

    return 0;
}