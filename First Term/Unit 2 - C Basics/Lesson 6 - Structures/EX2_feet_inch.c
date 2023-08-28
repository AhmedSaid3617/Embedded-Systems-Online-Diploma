#include<stdio.h>

struct SImperialLength
{
    float m_feet, m_inches;
};

struct SImperialLength Add(struct SImperialLength length1, struct SImperialLength length2){
    struct SImperialLength result;
    result.m_inches = length1.m_inches + length2.m_inches;
    result.m_feet = length1.m_feet + length2.m_feet;
    if (result.m_inches >=12){
        result.m_feet += (int)(result.m_inches/12);
        result.m_inches -= (int)(result.m_inches/12) * 12;
    }

    return result;
}

void printLength(struct SImperialLength length){
    printf("Sum of distances = %f\', %f\".", length.m_feet, length.m_inches);
}

void inputLength(struct SImperialLength length){
    printf("Enter feet: ");
    scanf("%f", &length.m_feet);
    printf("Enter inches: ");
    scanf("%f", &length.m_inches);
}


int main(){
    struct SImperialLength l1, l2;

    printf("Enter first length \n");
    printf("Enter feet: ");
    scanf("%f", &l1.m_feet);
    printf("Enter inches: ");
    scanf("%f", &l1.m_inches);

    printf("\nEnter second length \n");
    printf("Enter feet: ");
    scanf("%f", &l2.m_feet);
    printf("Enter inches: ");
    scanf("%f", &l2.m_inches);

    struct SImperialLength l3 = Add(l1, l2);

    printLength(l3);

    return 0;
}