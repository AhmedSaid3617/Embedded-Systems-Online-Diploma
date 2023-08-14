#include <stdio.h>

int main(){
    char command;
    float in1, in2;
    printf("Enter operator + - * /: ");
    scanf("%c", &command);
    printf("Enter operands: ");
    scanf("%f", &in1);
    scanf("%f", &in2);


    switch (command)
    {
    case '+':
        printf("Result = %f", in1 + in2);
        break;
    
    case '-':
        printf("Result = %f", in1 - in2);
        break;

    case '*':
        printf("Result = %f", in1 * in2);
        break;
    
    case '/':
        printf("Result = %f", in1/in2);
        break;
    
    default:
        printf("Wrong input");
        break;
    }
    return 0;
}