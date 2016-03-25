/* solved by me*/
#include<bits/stdc++.h>
#include<string>
using namespace std;
#define ll int
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
vector<ll> arr(1001);
vector<vector<ll> > mat(1001,vector<ll>(1001));
ll find_max_weight(ll num,ll sum)
{
    ll ans1,ans2,ans3;
    mat[0][0]=0;
    for(ll i=0;i<=num;i++)
        mat[0][i]=0;
    for(ll i=0;i<=sum;i++)
        mat[i][0]=0;
    for(ll i=1;i<=sum;i++)
    {
        for(ll j=1;j<=num;j++)
        {
            if(i>=arr[j])
            {
                if(j==1)
                    mat[i][j]=arr[j];
                else
                {
                    ans1=((mat[i-arr[j]][j-2]+arr[j])<=i ? (mat[i-arr[j]][j-2]+arr[j]) : 0);
                    ans2=arr[j];
                    ans3=mat[i][j-1];
                    mat[i][j]=max(ans1,ans3);                                  //max(ans2,ans3));
                }
            }
            else
                mat[i][j]=mat[i][j-1];
        }
    }
    return mat[sum][num];
}
int main()
{
    ll test,i,j,maxx,minn,num,m,ans;
    sc1int(test);
    for(ll j=1;j<=test;j++)
    {
        sc2int(num,maxx);
        for(i=1;i<=num;i++)
            sc1int(arr[i]);
        ans=find_max_weight(num,maxx);
        printf("Scenario #%d: %d\n",j,ans);
    }
}
