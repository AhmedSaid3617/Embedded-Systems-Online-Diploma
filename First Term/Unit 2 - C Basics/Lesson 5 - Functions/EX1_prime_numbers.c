#include <stdio.h>

void prime_numbers(int start, int end){
    char flag = 0;
    printf("Prime numbers are:");
    for (int i=start; i<end; i++){

        for (int j=i-1; j>1; j--){
            if (i%j == 0){
                flag =1;
                break;
            }
        }

        if(flag){
            flag =0;
            continue;
        }
        else
            printf(" %d ", i);
    }
}

int main() {
    int start, end;
    printf("Enter 2 numbers: ");
    scanf("%d", &start);
    scanf("%d", &end);
    prime_numbers(start, end);
}