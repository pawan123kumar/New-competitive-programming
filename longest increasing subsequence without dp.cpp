#include<bits/stdc++.h>
using namespace std;
int lis_final(int arr[],int n,int maxx);
void lis(int arr[],int n);
int main()
{
    int num;
    scanf("%d",&num);
    int arr[num];
    for(int i=0;i<num;i++)
        scanf("%d",&arr[i]);
    lis(arr,num);
}
void lis(int arr[],int n)
{
    int maxx=1;
    maxx=lis_final(arr,n,maxx);
    printf("%d is the longest increasing subsequence:",maxx);
}
int lis_final(int arr[],int n,int maxx)
{
    if(n==1)
        return 1;
    int res,max_end=1;
    for(int i=1;i<n;i++)
    {
        res=lis_final(arr,i,maxx);
        if(arr[i-1]<arr[n-1]&&(res+1)>max_end)
            max_end=res+1;
    }
    if(max_end>maxx)
        maxx=max_end;
    return max_end;
}

