//Given an array of integers which is rotated at position somewhere, find the minimum value in the array.
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> arr(1000001);
ll mid;
ll find_min_element(ll left,ll right)
{
    if(left>right)
        return arr[0];
    else if(left==right)
        return arr[left];
    mid=left+(right-left)/2;
    if(arr[mid]>arr[mid+1])//if next element is minimum
        return arr[mid+1];
    if((arr[mid]==arr[left])&&(arr[mid]==arr[right]))//in case of equal elements
        return min(find_min_element(left,mid-1),find_min_element(mid+1,right));
    if(arr[mid-1]>arr[mid])//in case of mid is minimum
        return arr[mid];
    if(arr[right]>arr[mid])
        return find_min_element(left,mid-1);
    return find_min_element(mid+1,right);
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
        ans=find_min_element(0,num-1);
        printf("%lld is the minimum element in the array:\n",ans);
    }
}

