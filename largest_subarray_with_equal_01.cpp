/* concept applied is find the subarray whose sum is zero, if we replace 0 by -1 */
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
vector<ll> hash_arr(100001);
void find_max_subarray_equal01(ll num)
{
    ll minn,maxx,i,j,max_size=-1,start_index;
    arr[0]=(arr[0]==0)?(-1):1;
    minn=arr[0];
    maxx=arr[0];
    for(ll i=1;i<num;i++)
    {
        arr[i]=(arr[i]==0)?(-1):1;
        arr[i]+=arr[i-1];
        minn=min(arr[i],minn);
        maxx=max(arr[i],maxx);
    }
    j=maxx-minn+1;
    for(i=0;i<j;i++)
        hash_arr[i]=-1;
    for(ll i=0;i<num;i++)
    {
        if(arr[i]==0)
        {
            max_size=i+1;
            start_index=0;
        }
        else
        {
            if(hash_arr[arr[i]-minn]==-1)
                hash_arr[arr[i]-minn]=i;
            else
            {
                if((i-hash_arr[arr[i]-minn])>max_size)
                {
                    max_size=i-hash_arr[arr[i]-minn];
                    start_index=hash_arr[arr[i]-minn]+1;
                }
            }
        }
    }
    if(max_size==(-1))
        printf("there is no subarray of equal number of 0's and 1's\n");
    else
        printf("Largest subarray possible is from %lld to %lld and size is (%lld)",start_index,start_index+max_size-1,max_size);
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
        find_max_subarray_equal01(num);
    }
}

