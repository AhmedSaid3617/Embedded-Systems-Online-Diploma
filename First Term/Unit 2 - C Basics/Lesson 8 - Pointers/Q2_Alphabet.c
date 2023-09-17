#include <stdio.h>

int main(){
    char alphabet[26] = {};
    for (int i=0; i<26; i++){
        alphabet[i] = (char)i + 65;
    }

    char *ptr = alphabet;
    char *end = &alphabet[26];
    for (;ptr <= end; ptr++){
        printf("%c ", *ptr);
    }

    return 0;
}