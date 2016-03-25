#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define gc getchar_unlocked
ll read_ll()
{
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  ll ret = 0;
  while(c>='0' && c<='9')
  {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
vector<ll> arr(10001);
vector<ll> dp(10001);
int main()
{
    ll test,i,j,num,k,ans;
    test=read_ll();
    for(ll k=1;k<=test;k++)
    {
        num=read_ll();//k=read_ll();
        for(ll i=0;i<num;i++)
            arr[i]=read_ll();
        if(num==0)
            ans=0;
        else if(num==1)
            ans=arr[0];
        else if(num==2)
            ans=max(arr[0],arr[1]);
        else
        {
            dp[0]=arr[0];
            dp[1]=max(arr[1],dp[0]);
            for(ll i=2;i<num;i++)
                dp[i]=max(dp[i-1],arr[i]+dp[i-2]);
            ans=dp[num-1];
        }
        printf("Case %lld: %lld\n",k,ans);
    }
}



