//here find the left and right index of the key values present in the array and calculate total occurences of number
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> arr(1000001);
ll find_right_pos(ll left,ll right,ll num,ll key)
{
    ll mid;
    while(right-left>1)
    {
        mid=left+(right-left)/2;
        if(key>=arr[mid])
            left=mid;
        else
            right=mid;
    }
    return left;
}
ll find_left_pos(ll left,ll right,ll num,ll key)
{
    ll mid;
    while(right-left>1)
    {
        mid=left+(right-left)/2;
        if(key<=arr[mid])
            right=mid;
        else
            left=mid;
    }
    return right;
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
        scanf("%lld",&key);
        ll left=find_left_pos(-1,num,num,key);//here (-1 to num) to handle case of all equal elements
        if(arr[left]==key)
        {
            right=find_right_pos(-1,num,num,key);//here (-1 to num) to handle case of all equal elements
            if(arr[right]==key)
                ans=right-left+1;
            else
                ans=0;
        }
        else
            ans=0;
        printf("%lld\n",ans);
    }
}

