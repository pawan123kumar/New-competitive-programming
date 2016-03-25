//Given an array, find an element before which all elements are smaller than it, and after which all are greater than it.
// Return index of the element if there is such an element, otherwise return -1.
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> arr(1000001),left_maxx(1000001),right_minn(1000001);
ll find_position(ll num)
{
    ll maxx,minn;
    left_maxx[0]=INT_MIN;
    for(ll i=1;i<num;i++)
        left_maxx[i]=max(left_maxx[i-1],arr[i-1]);
    right_minn[num-1]=arr[num-1];
    for(ll j=num-2;j>=0;j--)
        right_minn[j]=min(right_minn[j+1],arr[j+1]);
    for(ll i=1;i<(num-1);i++)
    {
        if((arr[i]>left_maxx[i])&&(arr[i]<right_minn[i]))
            return i;
    }
    return -1;
}
int main()
{
    ll test,i,j,a,b,num,ans;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&num);
        for(i=0;i<num;i++)
            scanf("%lld",&arr[i]);
        ans=find_position(num);
        if(ans==-1)
            cout<<"there is no such position found in array:\n";
        else
            cout<<"position required is: "<<ans<<" and element is: \n"<<arr[ans]<<endl;
    }
}

