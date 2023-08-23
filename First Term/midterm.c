#include <stdio.h>
#include <math.h>
#include <string.h>

int sumdigits(int num){
    int result = 0;
    int n = 1;
    while(num){
        result += num%10;
        num /= 10;
        n++;
    }

    return result;
}

double sRoot(int x){
    const double step = 0.001;

    for (double i = 0.0; i <= x; i+=step){
        if (x - pow(i, 2) < 0){
            return i - step;
        }
    }
}

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

int reverse_num(int num){

    int arr[100]={};
    int n = 0;
    while(num){
        arr[n] = num%10;
        num /= 10;
        n++;
    }
    n--;
    int result=arr[n];
    for(int i=0; i<n; i++){
        result += arr[i]*pow(10,n-i);
    }

    return result;
}

int num_ones(int num){
    int ones;
    while (num)
    {
        if(num%2 == 1)
            ones++;

        num >>= 1;
    }

    return ones;
    
}

int unique_number(int* arr, int size){
    int first[100] = {};
    int second[100];
    int count = 0;
    for (int i=0; i<size; i++){
        for (int j=0; j<=count; j++){
            if(arr[i] == first[j]){
                second[j] = arr[i];
            }
            else{
                first[count]=arr[i];
                count++;
            }
        }
    }

    for (int i=0; i<count; i++){
        if(first[i] != second[i])
            return first[i];
    }
    return -1;
}

int compute_sum(int n){
    static int sum;
    if(n == 0){
        return sum;
    }
    sum += n;
    return compute_sum(n-1);
}

void reverse(int* arr, int size){
    int output[100] = {};
    for (int i=0; i<size; i++){
        output[size-i-1] = arr[i];
    }

    for (int i=0; i<size; i++){
        arr[i] = output[i];
    }
}

void reverse_words(char* string){
    char output[100] = {};
    int size = strlen(string);
    int breakpoint = size;
    int k=0;
    for (int i=size; i>=0; i--){
        if (string[i] == ' ' || i==0){
            for (int j=i; j<breakpoint; j++, k++){
                output[k] = string[j];
            }
            breakpoint=i;
            output[k++] = ' ';
        }
    }

    for (int i=0; i<size+1; i++){
        string[i] = output[i];
    }
    string[size+1] = 0;
}

int max_ones(int x){
    int max=0;
    int count=0;
    while (x)
    {
        if(x%2==1){
            count++;
        }
        else{
            count = 0;
        }
        x >>=1;
        max = (count > max)?count:max;
    }

    return max;
    
}

int main(){
    printf("%d\n", max_ones(14));
    printf("%d", max_ones(110));
    return 0;
}