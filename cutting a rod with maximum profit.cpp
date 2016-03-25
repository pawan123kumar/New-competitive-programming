#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll arr_price[100000];
ll table[100000];
ll num;
ll cut_rod_max_price()
{
    ll i,j,max_val;
    table[0]=0;
    for(i=1;i<=num;i++)
    {
        max_val=INT_MIN;
        for(j=0;j<i;j++)
            max_val=max(max_val,arr_price[j]+table[i-j-1]);
        table[i]=max_val;
    }
    return table[num];
}
int main()
{
    ll i,j,test,max_cost;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&num);
        for(i=0;i<num;i++)
            scanf("%lld",&arr_price[i]);
        max_cost=cut_rod_max_price();
        printf("%lld is the maximum price for cutting rod of length: %lld\n",max_cost,num);
    }
}

