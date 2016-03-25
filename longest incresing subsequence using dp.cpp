#include<bits/stdc++.h>
void LIS(int arr[],int num);
using namespace std;
int main()
{
    int num;//total number of elements in the array:
    scanf("%d",&num);
    int arr[num];
    for(int i=0;i<num;i++)
        scanf("%d",&arr[i]);
    LIS(arr,num);
}
void LIS(int arr[],int num)
{
    int LIS[num],maxx=1;
    for(int i=0;i<num;i++)
        LIS[i]=1;
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<i;j++)
        {
            if((arr[i]>arr[j])&&(LIS[j]+1>LIS[i]))
                LIS[i]=LIS[j]+1;
        }
    }
    for(int i=0;i<num;i++)
    {
        if(LIS[i]>maxx)
            maxx=LIS[i];
    }
    printf("%d is the longest increasing common subsequence:",maxx);
}

