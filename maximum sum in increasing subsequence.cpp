#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll arr[10000],num,table[10000];
ll max_sum_increasing_subs()
{
    ll i,j,maxx;
    for(i=0;i<num;i++)
        table[i]=arr[i];
    for(i=1;i<num;i++)
    {
        for(j=0;j<i;j++)
        {
            if((arr[i]>arr[j])&&((table[i])<(table[j]+arr[i])))
               table[i]=table[j]+arr[i];
        }
    }
    maxx=table[0];
    for(i=1;i<num;i++)
        if(maxx<table[i])
           maxx=table[i];
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
        printf("the maximum sum of increasing subsequence is:%lld\n",ans);
    }
}

