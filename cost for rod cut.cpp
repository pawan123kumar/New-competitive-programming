//divide the rod into the parts such that the cost becomes maximum...:)
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define sc(x) scanf("%lld",&x)
vector<ll> val(1000001);
vector<ll> price(1000001);
void cut_rod_max_cost(ll num)
{
    ll max_val;
    val[0]=0;
    for(ll i=1;i<=num;i++)
    {
        max_val=INT_MIN;
        for(ll j=0;j<i;j++)
            max_val=max(max_val,price[j]+val[i-j-1]);
        val[i]=max_val;
    }
    cout<<"maximum price is: "<<val[num]<<endl;
}
int main()
{
    ll a,i,j,test,num;
    sc(test);
    while(test--)
    {
        sc(num);
        for(i=0;i<num;i++)
            sc(price[i]);
        cut_rod_max_cost(num);
    }
}

