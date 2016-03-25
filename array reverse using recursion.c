/*reverse an array using recursion*/
#include<stdio.h>
#define maxx 50
main()
{
    int arr[maxx],i,j,n;
    printf("enter total elements of array:");
    scanf("%d",&n);
    printf("\n enter elements in array:");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
        reverse_array(arr,n);
        printf("\n the array after reversing is as:");
    for(i=0;i<n;i++)
        printf("%2d",arr[i]);
}
void reverse_array(int arr[],int n)
{
    int temp;
    if(n==0||n==1)
        return;
    else
    {
        temp=arr[0];
        arr[0]=arr[n-1];
        arr[n-1]=temp;
        reverse_array(arr+1,(n-2));
    }
}
