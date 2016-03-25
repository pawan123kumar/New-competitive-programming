#include<bits/stdc++.h>
#include<string>
using namespace std;
#define ll long long int
vector<ll> dp(5001);
char str[5001];
int main()
{
    int now,last,i,j,len;
    ll ans;
    while(1)
    {
        scanf("%s",str);
        if(str[0]=='0')
            break;
        len=strlen(str);
        bool flag=false;
        fill(dp.begin(),dp.begin()+len,0);
        dp[0]=1;
        last=str[0]-'0';
        for(i=1;i<len;i++)
        {
            if(str[i]-'0')
                dp[i]=dp[i-1];
            last=10*(str[i-1]-'0')+str[i]-'0';
            if(last>9&&(last<=26))
                dp[i]+=dp[(i-2)<0?0:(i-2)];
        }
        printf("%lld\n",dp[len-1]);
    }
}

