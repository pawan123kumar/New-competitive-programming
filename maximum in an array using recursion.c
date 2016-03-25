#include<stdio.h>
#define maxxx 20
int maxx(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int maxin_array(int arr[],int n)
{
    int max_value=arr[0];
    if(n==0)
        return -999999;
    else if(n==1)
    return arr[0];
    else return maxx(max_value,maxin_array(arr+1,n-1));
}
main()
{
    int i,n,arr[maxxx];
    printf("enter the total elements in array:");
    scanf("%d",&n);
    printf("\n enter the elements in array:");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
        printf("\n the maximum in the array is as:%d",maxin_array(arr,n));
}
