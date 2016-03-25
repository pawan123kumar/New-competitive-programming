//here the values of num and m are given..m is the number of steps we can take at a time and num is the total stairs..
//so we have to find out the total ways,reach to the nth stair
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define sc1(x) scanf("%lld",&x)
#define sc2(x,y) scanf("%lld%lld",&x,&y)
vector<ll> ans(10001);
void find_total_ways(ll num,ll m)
{
    ans[0]=1,ans[1]=1;
    for(ll i=2;i<num;i++)
    {
        ans[i]=0;
        for(ll j=1;(j<=i)&&(j<=m);j++)
            ans[i]+=ans[i-j];
    }
    cout<<ans[num-1]<<endl;
}
int main()
{
    ll m,test,i,j,minn,maxx,num;
    sc1(test);
    while(test--)
    {
        sc2(num,m);
        num=num+1;
        find_total_ways(num,m);
    }
}

