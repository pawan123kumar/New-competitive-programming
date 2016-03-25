//Fixed Point in an array is an index i such that arr[i] is equal to i
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> arr(1000001);
ll mid;
ll find_fixed_element_pos(ll left,ll right)
{
    while(left<right)
    {
        mid=left+(right-left)/2;
        if(mid==arr[mid])
            return mid;
        else if(mid>arr[mid])
            left=mid+1;
        else
            right=mid-1;
    }
    return -1;
}
int main()
{
    ll ans,test,num,i,j,key;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&num);
        for(i=0;i<num;i++)
            scanf("%lld",&arr[i]);
        ans=find_fixed_element_pos(0,num-1);
        printf("%lld\n",ans);
    }
}

