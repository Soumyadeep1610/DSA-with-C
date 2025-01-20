#include<stdio.h>
int main()
{
float fahrenheit,centigrade;
printf("Enter the temparature in degree centigrade:");
scanf("%f",&centigrade);
fahrenheit=((centigrade*9)/5)+32;
printf("\n The temparature in fahrenheit is: %f",fahrenheit);
return 0;
}