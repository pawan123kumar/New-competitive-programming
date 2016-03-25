#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll count_trials(ll n,ll k)//here n is the number of eggs and k are floors
{
    ll minn,i,j,x,table[n+1][k+1];
    for(i=1;i<=n;i++)
    {
        table[i][1]=1;//it means if we have 1 floor,then we need only 1 egg to test
        table[i][0]=0;//it means if we don't have any floor,then no need of any egg
    }
    for(j=1;j<=k;j++)
        table[1][j]=j;//it means if we have only 1 egg..then for j floors we need j trials
    for(i=2;i<=n;i++)//total number of eggs
    {
        for(j=2;j<=k;j++)//total number of floors
        {
            table[i][j]=INT_MAX;
            for(x=1;x<=j;x++)//trial for each floor
            {
                minn=1+max(table[i-1][x-1],table[i][j-x]);//it means either egg can break or not case 1.if egg breaks then egg
                //remains=i-1 and floor remains=x-1,so table[i-1][x-1].....case 2.if egg don't breaks..then egg remains=i..but
                //we tested x floor...so number of floors remain=k-x...so for 2nd case table[i][j-x]...
                //and we take maxx of both cases because we want minimum in both of them...
                if(minn<table[i][j])
                    table[i][j]=minn;
            }
        }
    }
    return table[n][k];
}
int main()
{
    ll test,n,k,total_trials;
    scanf("%lld",&test);
    while(test--)
    {
        printf("enter the number of eggs and number of floors:");
        scanf("%lld%lld",&n,&k);
        total_trials=count_trials(n,k);
        printf("%lld trials required:\n",total_trials);
    }
}

