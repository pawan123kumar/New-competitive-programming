#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define li long int
#define prnt_newline printf("\n")
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
struct knap_item
{
    ll item_size,val;
};
vector<knap_item> arr(101);
vector<vector<ll> > mat(501,vector<ll>(101));
void knapsack(ll capacity,ll num)
{
    ll maxx=0,ans=0;
    for(ll i=0;i<=capacity;i++)
    {
        for(ll j=0;j<=num;j++)
        {
            if(i==0||j==0)
                mat[i][j]=0;
            else if(i>=(arr[j].item_size))
                mat[i][j]=max(mat[i-arr[j].item_size][j-1]+arr[j].val,mat[i][j-1]);
            else
                mat[i][j]=mat[i][j-1];
            if(mat[i][j]>maxx)
            {
                maxx=mat[i][j];
                ans=i;
            }
            //cout<<mat[i][j]<<" ";
        }
        //cout<<endl;
    }
    printf("%lld %lld\n",ans,maxx);
}
int main()
{
    ll capacity,items,zero=0;
    while(1)
    {
        scanf("%lld%lld",&capacity,&items);
        if((capacity==zero)&&(items==zero))
            break;
        for(ll i=1;i<=items;i++)
            scanf("%lld%lld",&arr[i].item_size,&arr[i].val);
        knapsack(capacity,items);
    }
}




