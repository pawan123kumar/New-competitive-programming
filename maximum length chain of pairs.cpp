//You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.
// A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion.
// Find the longest chain which can be formed from a given set of pairs.
//For example, if the given pairs are {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} },
//then the longest chain that can be formed is of length 3, and the chain is {{5, 24}, {27, 40}, {50, 90}}
//Hint : - this problem is a variation of LIS
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
struct node
{
    ll a,b;
};
vector<ll> table(100001);
vector<struct node> arr(100001);
void find_longest_chain_pairs(ll num)
{
    ll maxx=1;
    for(ll i=0;i<num;i++)
        table[i]=1;
    for(ll i=1;i<num;i++)
    {
        for(ll j=0;j<i;j++)
        {
            if((arr[i].a>arr[j].b)&&((table[j]+1)>table[i]))
            {
                table[i]=table[j]+1;
                if(table[i]>maxx)
                    maxx=table[i];
            }
        }
    }
    cout<<maxx<<endl;
}
int main()
{
    ll test,a,b,maxx,minn,total,num;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&num);
        for(ll i=0;i<num;i++)
            scanf("%lld%lld",&arr[i].a,&arr[i].b);
        find_longest_chain_pairs(num);
    }
}

