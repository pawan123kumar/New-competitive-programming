#include<stdio.h>
#define maxx 50
main()
{
    int arr[maxx],i,j,n,temp;
    printf("enter total elements of array:");
    scanf("%d",&n);
    printf("\n enter elements in array:");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0,j=n-1;i<j;i++,j--)
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
        printf("\n the array after reversing is as:");
    for(i=0;i<n;i++)
        printf("%2d",arr[i]);
}
