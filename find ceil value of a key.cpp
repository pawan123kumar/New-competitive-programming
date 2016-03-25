//here ceil value means that we have to return equal value if present...else return just greater than value present in the array
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> arr(1000001);
ll find_ceil(ll left,ll right,ll num,ll key)
{
    ll mid;
    while(right-left>1)
    {
        mid=left+(right-left)/2;
        if(arr[mid]>=key)
            right=mid;
        else
            left=mid;
    }
    return arr[right];
}
int main()
{
    ll test,num,i,j,key;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&num);
        for(i=0;i<num;i++)
            scanf("%lld",&arr[i]);
        scanf("%lld",&key);
        ll ans=find_ceil(0,num-1,num,key);
        printf("%lld\n",ans);
    }
}

