#include<bits/stdc++.h>
#include<string>
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
vector<vector<bool> > mat(50001,vector<bool>(101));
vector<ll> arr(101);
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
bool partition_subset(ll sum,ll num)
{
    for(ll i=0;i<=num;i++)
        mat[0][i]=true;
    for(ll i=0;i<=sum;i++)
        mat[i][0]=false;
    for(ll i=1;i<=sum;i++)
    {
        for(ll j=1;j<=num;j++)
        {
            mat[i][j]=mat[i][j-1];
            if(i>=arr[j-1])
                mat[i][j]=mat[i][j]||mat[i-arr[j-1]][j-1];
        }
    }
    return mat[sum][num];
}
int main()
{
    ll test,i,j,num,m,sum;
    test=read_ll();
    //scanf("%d",&test);
    while(test--)
    {
        sum=0;
        num=read_ll();
        //scanf("%d",&num);
        for(i=0;i<num;i++)
        {
            arr[i]=read_ll();
            //scanf("%d",&arr[i]);
            sum+=arr[i];
        }
        if(sum%2!=0)
            printf("NO\n");
        else
        {
            if(partition_subset(sum/2,num))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}

