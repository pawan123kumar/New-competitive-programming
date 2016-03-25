#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> arr(100001);
ll mid1,mid2;
ll ternary_search(ll left,ll right,ll key)
{
    if(left<=right)
    {
        mid1=left+(right-left)/3;
        mid2=mid1+(right-left)/3;
        if(arr[mid1]==key)
            return mid1;
        else if(arr[mid2]==key)
            return mid2;
        else if(key<arr[mid1])
            return ternary_search(left,mid1-1,key);
        else if(key>arr[mid2])
            return ternary_search(mid2+1,right,key);
        else
            return ternary_search(mid1+1,mid2-1,key);
    }
    return -1;
}
int main()
{
    ll test,a,b,c,num,i,j,key,ans;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&num);
        for(i=0;i<num;i++)
            scanf("%lld",&arr[i]);
        scanf("%lld",&key);
        ans=ternary_search(0,num-1,key);
        if(ans==-1)
            printf("key is not present:\n");
        else
            printf("key is present at position %lld\n",ans);
    }
}

