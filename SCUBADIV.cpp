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
struct knap_item
{
    ll oxy,nitro,wt;
};
vector<struct knap_item> arr(1001);
ll mat[1001][22][80];
void knapsack(ll oxy_need,ll nitro_need,ll num)
{
    ll maxx=0;
    for(ll k=0;k<=num;k++)
    {
        for(ll i=0;i<=oxy_need;i++)
        {
            for(ll j=0;j<=nitro_need;j++)
            {
                if(k==0)
                {
                    mat[k][i][j]=INT_MAX;
                    if((i==0)&&(j==0))
                        mat[k][i][j]=0;
                }
                else
                    mat[k][i][j]=min( (arr[k].wt+mat[k-1][max(maxx,i-arr[k].oxy)][max(maxx,j-arr[k].nitro)]) ,mat[k-1][i][j]);
            }
        }
    }
    printf("%lld\n",mat[num][oxy_need][nitro_need]);
}
int main()
{
    ll test,i,j,num,oxy_need,nitro_need;
    test=read_ll();
    //scanf("%lld",&test);
    while(test--)
    {
        oxy_need=read_ll();nitro_need=read_ll();num=read_ll();
        //scanf("%lld%lld%lld",&oxy_need,&nitro_need,&num);
        for(ll i=1;i<=num;i++)
        {
            arr[i].oxy=read_ll();arr[i].nitro=read_ll();arr[i].wt=read_ll();
        }
            //scanf("%lld%lld%lld",&arr[i].oxy,&arr[i].nitro,&arr[i].wt);
        knapsack(oxy_need,nitro_need,num);
    }
}



