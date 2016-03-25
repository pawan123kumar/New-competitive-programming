/*remember for this 1+2+..+9=45 */
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
ll arr[20];
ll find_sum(ll num)//if num=328
{
    if(num<10)
        return (num*(num+1))/2; //if num is from 0 t0 9 ,then direct answer is num*(num+1)/2
    ll d=log10(num);//it finds the {digits in the number-1}
    ll *a=new ll[d+1];
    a[0]=0,a[1]=45;
    for(ll i=2;i<=d;i++)
        a[i]=a[i-1]*10+45*arr[i-1];//find sum of digits upto 300
    ll p=arr[d];
    ll msd=num/p;
    return ( msd*a[d] + ((msd*(msd-1))/2) * p + msd*(1+num%(p)) + find_sum(num%p) );// {3*sum[99]+3*(3-1)/2} - upto 300 + 3*(1+28 + find_sum(28))
}
int main()
{
    ll i,j,maxx,minn,num,m,sum,a,b,term_a=-1;
    arr[0]=1;
    for(i=1;i<=15;i++)
        arr[i]=arr[i-1]*10;
    int test;
    //sc1int(test);
    while(1)
    {
        sc2ll(a,b);
        if((a==term_a)&&(b==term_a))
            break;
        //scanf("%lld%lld",&a,&b);
        sum=find_sum(b);
        if(a>0)
            sum-=find_sum(a-1);
        printf("%lld\n",sum);
    }
}

