#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll arr[10000],num,table_lis[10000],table_lds[10000];
ll max_sum_increasing_subs()
{
    ll i,j,maxx;
    for(i=0;i<num;i++)
    {
        table_lis[i]=1;//table is for increasing subsequence
        table_lds[i]=1;//table is for decreasing subsequence
    }
    for(i=1;i<num;i++)//for increasing subsequence
    {
        for(j=0;j<i;j++)
        {
            if((arr[i]>arr[j])&&((table_lis[i])<(table_lis[j]+1)))
               table_lis[i]=table_lis[j]+1;
        }
    }
    for(i=num-2;i>=0;i--)//for decreasing order subsequence..means in reverse order increasing subsequence
    {
        for(j=num-1;j>i;j--)
        {
            if(arr[i]>arr[j]&&table_lds[i]<table_lds[j]+1)
                table_lds[i]=table_lds[j]+1;
        }
    }
    maxx=table_lds[0]+table_lis[0]-1;
    for(i=1;i<num;i++)
    {
        if(maxx<table_lds[i]+table_lis[i]-1)
           maxx=table_lds[i]+table_lis[i]-1;
    }
    return maxx;
}
int main()
{
    ll ans,test,i,j;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&num);
        for(i=0;i<num;i++)
            scanf("%lld",&arr[i]);
        ans=max_sum_increasing_subs();
        printf("bitonic subsequence is of length:%lld\n",ans);
    }
}

