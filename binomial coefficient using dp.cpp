#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll coefficient(ll n,ll k)
{
    if(k>n)
        return -1;
    ll i,j,arr[n+1][k+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=k;j++)
            arr[i][j]=0;
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=min(i,k);j++)
        {
            if(j==0||j==i)
                arr[i][j]=1;
            else
                arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
        }
    }
    /*for(i=0;i<=n;i++)
    {
        for(j=0;j<=k;j++)
            printf("%lld ",arr[i][j]);
        printf("\n");
    }*/ //to ensure the output ..print the whole table
    return arr[n][k];
}
int main()
{
    ll n,k;
    scanf("%lld%lld",&n,&k);
    ll coeff=coefficient(n,k);
    if(coeff==-1)
        printf("k is greater than n:");
    else
        printf("%lld",coeff);
}


