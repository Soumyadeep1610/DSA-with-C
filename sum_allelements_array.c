#include<stdio.h>
int main()
{
int size;
printf("Enter the size of the array:");
scanf("%d",&size);
int a[size],i,s;
printf("Enter array elements:\n");
for(i=0;i<size;i++)
scanf("%d",&a[i]);
s=0;
for(i=0;i<size;i++)
s=s+a[i];
printf("Sum of the array is: %d",s);
return 0;
