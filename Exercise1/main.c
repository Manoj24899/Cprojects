#include <stdio.h>
int main()
{
    float basic_sal;
    float dearness;
    float house_rent;
    float gross_sal;
    printf("enter basic salary:");
    scanf("%f",&basic_sal);

    //calculate dearness
    dearness=basic_sal*40/100;
    printf("%f\n",dearness);

    //calculate house rent
    house_rent=basic_sal*20/100;
    printf("%f\n",house_rent);

    //calculate gross sal
    gross_sal=basic_sal-dearness-house_rent;
    printf("%f\n",gross_sal);
    return 0;
}
