#include <stdio.h>

int factorial(int x){
    if(x == 2)
        return 2;
    else
        return x * factorial(x-1);
}

int main(){
    int input;
    printf("Enter a positive number: ");
    scanf("%d", &input);
    printf ("Factorial of %d is %d", input, factorial(input));

    return 0;
}