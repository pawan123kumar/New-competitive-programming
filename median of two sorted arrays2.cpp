//Given two array of integers , find the median.Median is possible only if equal elements in both arrays
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll m1,m2;
ll get_mid(ll arr[],ll num)
{
    if(num%2!=0)
        return arr[num/2];
    else
        return (arr[(num/2)-1]+arr[num/2])/2;
}
ll find_median(ll arr1[],ll arr2[],ll num)
{
    if(num<=0)
        return -1;
    if(num==1)
        return (arr1[0]+arr2[0])/2;
    if(num==2)
        return (max(arr1[0],arr2[0])+min(arr1[1],arr2[1]))/2;
    ll m1=get_mid(arr1,num);
    ll m2=get_mid(arr2,num);
    if(m1==m2)
        return m1;
    if(m1>m2)
    {
        if(num%2==0)
            return find_median(arr2+num/2-1,arr1,num-num/2+1);
        else
            return find_median(arr2+num/2,arr1,num-num/2);
    }
    else
    {
        if(num%2==0)
            return find_median(arr1+num/2-1,arr2,num-num/2+1);
        else
            return find_median(arr1+num/2,arr2,num-num/2);
    }
}

int main()
{
    ll ans,test,num,i,j,key;
    scanf("%lld",&test);
    ll arr1[10001],arr2[10001];
    while(test--)
    {
        scanf("%lld",&num);
        for(i=0;i<num;i++)
            scanf("%lld",&arr1[i]);
        for(i=0;i<num;i++)
            scanf("%lld",&arr2[i]);
        ans=find_median(arr1,arr2,num);
        printf("%lld is the median of given array:\n",ans);
    }
}

