//here find the element position at which element value is greater than its neighbors elements
//for example in { 10,20,15,2,23,90,67 } there are two peak elements in the this example 20,90..we can return any one of them
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> arr(1000001);
ll mid;
ll find_peak_element_pos(ll left,ll right)
{
    if(right<left)
        return -1;
    mid=left+(right-left)/2;
    if((arr[mid]>=arr[left])&&(arr[mid]>=arr[right]))
        return mid;
    if(arr[left]>arr[mid])//if middle element is less than its left neighbor,then peak element is in the left half
        return find_peak_element_pos(left,mid-1);
    return find_peak_element_pos(mid+1,right);
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
        ans=find_peak_element_pos(0,num-1);
        printf("%lld\n",ans);
    }
}

