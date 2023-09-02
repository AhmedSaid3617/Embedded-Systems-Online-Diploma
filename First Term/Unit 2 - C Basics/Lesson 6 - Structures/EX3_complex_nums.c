#include <stdio.h>

struct SComplex
{
    float real;
    float imaginary;
};

struct SComplex Add(struct SComplex num1, struct SComplex num2);

int main(){
    struct SComplex num1, num2, result;

    printf("Enter 1st complex num.\nEnter real and imaginary respectively: ");
    scanf("%f", &num1.real);
    scanf("%f", &num1.imaginary);
    
    printf("Enter 2nd complex num.\nEnter real and imaginary respectively: ");
    scanf("%f", &num2.real);
    scanf("%f", &num2.imaginary);

    result = Add(num1, num2);

    printf("Result:\n");
    printf("%f + %fi", result.real, result.imaginary);
    
    
    return 0;
}

struct SComplex Add(struct SComplex num1, struct SComplex num2){
    struct SComplex result = {num1.real + num2.real, num1.imaginary + num2.imaginary};
    return result;
}