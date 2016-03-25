//Given an array of integers which is initially increasing and then decreasing, find the maximum value in the array.
//this method only works for non-repeating numbers
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> arr(1000001);
ll mid;
ll find_max_element_pos(ll left,ll right)
{
    while(left<right)
    {
        mid=left+(right-left)/2;
        if((arr[mid]>arr[mid+1])&&(arr[mid]>arr[mid-1]))
            return mid;
        else if(arr[mid]>arr[mid+1])
            right=mid-1;
        else
            left=mid+1;
    }
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
        ans=find_max_element_pos(0,num-1);
        printf("max element %lld is at position:%lld\n",arr[ans],ans);
    }
}

