#include<stdio.h>
int main()
{
int a[10],n;
int l1,l2,i;
printf("Enter the number of array elements:");
scanf("%d",&n);
printf("Enter array elements:");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
l1=a[0];
for(i=0;i<n;i++)
{
if(a[i]>l1)
{
l1=a[i];
}
}
l2=a[0];
for(i=1;i<n;i++)
{
if(a[i]>l2 && a[i]<l1)
l2=a[i];
}
printf("The largest number is: %d",l1);
printf("\nThe second largest number is: %d",l2);
}