/*this is the nice dp problem in which u have to think ad-hoc approach, but from last position*/
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
vector<ll> arr(100010);
vector<ll> dp(100010);
int main()
{
    ll i,j,num,maxx,minn;
    int test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%lld",&num);
        for(i=0;i<num;i++)
            sc1ll(arr[i]);
        if(num<=3)
        {
            maxx=0;
            for(i=0;i<num;i++)
                maxx+=arr[i];
            printf("%lld\n",maxx);
            continue;
        }
        dp[num]=0;dp[num+1]=0;dp[num+2]=0;dp[num+3]=0;dp[num+4]=0;dp[num+5]=0;dp[num+6]=0;
        arr[num]=0;arr[num+1]=0;arr[num+2]=0;arr[num+3]=0;arr[num+4];
        for(i=num-1;i>=0;i--)
            dp[i]=max(arr[i]+dp[i+2],max(arr[i]+arr[i+1]+dp[i+4],arr[i]+arr[i+1]+arr[i+2]+dp[i+6]));
        printf("%lld\n",dp[0]);
    }
}

