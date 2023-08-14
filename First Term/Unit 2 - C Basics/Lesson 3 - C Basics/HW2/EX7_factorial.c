#include <stdio.h>
int main(){
    int input;
    int result = 1;
    printf("Enter an integer number: ");
    scanf("%d", &input);
    if(input < 0){
        printf("Error");
    }
    else{
        for(int i=input; i>0; i--){
            result *= i;
        }
        printf("\n%d", result);
    }
    return 0;
}