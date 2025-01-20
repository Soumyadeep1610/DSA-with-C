#include<stdio.h>
int main()
{
int a[20];
int i,j,t,n;
printf("Enter the number of array elements:");
scanf("%d",&n);
printf("Enter the array elements:");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if (a[i]>a[j])
{
t=a[i];
a[i]=a[j];
a[j]=t;
}
}
}
printf("Sorting elements are:");
for(i=0;i<n;i++)
printf("%d\n",a[i]);
}