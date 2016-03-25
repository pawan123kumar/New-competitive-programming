/*find sum of digits between a and b */
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
ll find_sum(ll N)
{
    if(N/10==0)
        return N*(N+1)/2;
    int i=0;
    ll n=N;
    while(n/10!=0)
    {
        i++;
        n/=10;
    }
    ll p=pow(10,i);
    return ((n*45*i*p/10)+ n*(n-1)*p/2+ n*(N%p+1) + find_sum(N%p));
}
#define pc(x) putchar_unlocked(x)
inline void writeInt(ll n)
{
        ll N = n, rev, count = 0;
        rev = N;
        if (N == 0) { pc('0'); pc('\n'); return ;}
        while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
        rev = 0;
        while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
        while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
        while (count--) pc('0');
        pc('\n');
}
int main()
{
    ll i,j,maxx,minn,num,m,sum,a,b,term_a=-1;
    arr[0]=1;
    for(i=1;i<=15;i++)
        arr[i]=arr[i-1]*10;
    int test;
    sc1int(test);
    while(test--)
    {
        a=read_ll();b=read_ll();
        //scanf("%lld%lld",&a,&b);
        sum=find_sum(b);
        if(a>0)
            sum-=find_sum(a-1);
        writeInt(sum);
    }
}

