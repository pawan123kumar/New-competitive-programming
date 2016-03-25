/* nice problem ...not done by myself ..read editorial for removing duplicates and then done it on my own*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define li long int
#define prnt_newline printf("\n")
#define fr0(a,b) for(i=0;i<a;i+=b)
#define fr1(a,b) for(i=1;i<=a;i+=b)
#define set_bits(x) __builtin_popcount(x)
#define sc1int(x) scanf("%d",&x)
#define sc2int(x,y) scanf("%d%d",&x,&y)
#define sc1li(x) scanf("%ld",&x)
#define sc2li(x,y) scanf("%ld%ld",&x,&y)
#define sc1ll(x) scanf("%lld",&x)
#define sc2ll(x,y) scanf("%lld%lld",&x,&y)
#define sc3ll(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define prntint(x) printf("%d",x)
#define prntli(x) printf("%d",x)
#define prntll(x) printf("%lld",x)
#define mod_val 1000000007
vector<ll> last_pos(52,0);
vector<ll> dp(100001);
char str[100001];
int main()
{
    ll ans,i,j,num,maxx,minn,m,len;
    int test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%s",str);
        fill(last_pos.begin(),last_pos.end(),0);
        len=strlen(str);
        ans=0;
        dp[0]=1;
        for(i=1;i<=len;i++)
        {
            dp[i]=(dp[i-1]*2)%mod_val;
            if(dp[i]<0)
                dp[i]+=mod_val;
            if(last_pos[str[i-1]-'A']>0)
                dp[i]=dp[i]-dp[last_pos[str[i-1]-'A']-1];
            if(dp[i]<0)
                dp[i]+=mod_val;
            dp[i]=dp[i]%mod_val;
            last_pos[str[i-1]-'A']=i;
        }
        printf("%lld\n",dp[len]);
    }
}


