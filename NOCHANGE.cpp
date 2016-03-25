/*  equation for solution is :  n1*v1+n2*v2...+nk*vk=x;     { where n1>=n2>=n3...>=nk; } */
#include<bits/stdc++.h>
using namespace std;
#define ll  int
int main()
{
    ll num,i,j,a,b,k,x;
    scanf("%d%d",&x,&k);
    vector<bool> ans(x+1,false);
    vector<ll> dp(k);
    for(i=0;i<k;i++)
    {
        scanf("%d",&dp[i]);
        if(i>0)
            dp[i]=dp[i]+dp[i-1];
    }
    ans[0]=true;
    for(i=0;i<k;i++)
    {
        for(j=dp[i];j<=x;j++)
        {
            ans[j]=ans[j]||ans[j-dp[i]];
        }
    }
    if(ans[x]==true)
        printf("YES\n");
    else
        printf("NO\n");
}
