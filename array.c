#include<stdio.h>
int main()
{
int a[5];
int i;
printf("Enter the array elements:");
for(i=0;i<5;i++)
{
scanf("%d",&a[i]);
}
printf("The array elements are:");
for(i=0;i<5;i++)
{
printf("%d",a[i]);
}
return 0;
}
