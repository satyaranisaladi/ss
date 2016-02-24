#include<stdio.h>
//#include</home/bossmool/satya/sort.h>
//extern bubble();
main()
{
int i,j,temp;
printf("enter values of i&j:");
scanf("%d%d",&i,&j);
temp=i;
i=j;
j=temp;
printf("after swapping values: i=%d j=%d",i,j);
bubble();
}
void bubble()
{
int n,i,j,a[10],temp;
printf("enter size of array:");
scanf("%d",&n);
printf("enter %d elements :",n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=1;i<=n-1;i++)
{
for(j=0;j<=n-i;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
printf("after sorting:");
for(i=0;i<n;i++)
printf("%d",a[i]);
}
