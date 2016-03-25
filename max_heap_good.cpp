#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> arr(1001);
void heapify(ll index,ll num)
{
    ll val=arr[index];
    ll left=index*2,right=left+1;
    while(right<=num)
    {
        if(val>=arr[right]&&val>=arr[left])
        {
            arr[index]=val;
            return;
        }
        else if(arr[left]>arr[right])
        {
            arr[index]=arr[left];
            index=left;
        }
        else
        {
            arr[index]=arr[right];
            index=right;
        }
        left=index*2;
        right=left+1;
    }
    if(left==num&&arr[left]>val)
    {
        arr[index]=arr[left];
        index=left;
    }
    arr[index]=val;
}
int main()
{
    ll test,a,b,num,i,j,wt;
    scanf("%lld",&test);
    string str1,str2;
    while(test--)
    {
        scanf("%lld",&num);
        for(i=1;i<=num;i++)
            scanf("%lld",&arr[i]);
        for(i=num/2;i>=1;i--)
            heapify(i,num);
        ll total=0;
        for(i=1;i<=num;i++)
        {
            printf("%lld ",arr[1]);
            arr[1]=arr[num-total];
            total++;
            heapify(1,num-total);
        }
    }
}

