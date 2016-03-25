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
vector<ll> arr(100001);
void sort_array_012(ll num)
{
    ll low=0,mid=0,hi=num-1;
    while(mid<=hi)
    {
        switch(arr[mid])
        {
        case 0:
            swap(arr[low],arr[mid]);
            low++,mid++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(arr[mid],arr[hi]);
            hi--;
        }
    }
    for(ll i=0;i<num;i++)
        printf("%lld ",arr[i]);
    printf("\n");
}
int main()
{
    ll test,i,j,num;
    sc1ll(test);
    while(test--)
    {
        sc1ll(num);
        for(i=0;i<num;i++)
            sc1ll(arr[i]);
        sort_array_012(num);
    }
}

