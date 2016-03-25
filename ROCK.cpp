#include<bits/stdc++.h>
#include<string>
using namespace std;
#define ll long long int
#define lli int
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
char str[201];
vector<lli> dp(201);
int main()
{
    lli cnt1,cnt0,len,test,i,j,ans,max_len,maxx;
    sc1int(test);
    while(test--)
    {
        sc1int(len);
        scanf("%s",str);
        //len=strlen(str);
        if((str[0]-'0')==0)
            dp[0]=0;
        else
            dp[0]=1;
        for(i=1;i<len;i++)
        {
            cnt1=0,cnt0=0,maxx=0,max_len=0;
            for(j=i;j>=0;j--)
            {
                if((str[j]-'0')==0)
                    cnt0++;
                else
                    cnt1++;
                if(cnt1>cnt0)
                    max_len=max(cnt1+cnt0,max_len);
                maxx=max(max_len,maxx);
                if(j!=0)
                    maxx=max(maxx,max_len+dp[j-1]);

            }
            dp[i]=maxx;
        }
        printf("%d\n",dp[len-1]);
    }
}

