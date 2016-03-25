#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> arr(101);
ll num;
void restore_down(int index,ll h_size);
int deletion();
int main()
{
    ll i,j;
    scanf("%lld",&num);
    for(i=1;i<=num;i++)
        scanf("%lld",&arr[i]);
    for(i=num/2;i>=1;i--)//this builds up heap tree in bottom up order...so takes O(n) time..:)
        restore_down(i,num);
    printf("after heap sort array elements are as:\n");
    while(num!=0)
        printf("%lld ",deletion());
}
void restore_down(int index,ll h_size)
{
    ll val=arr[index];
    int left=index*2;
    int right=left+1;
    while(right<=h_size)
    {
        if(val<=arr[left]&&val<=arr[right])
        {
            arr[index]=val;
            return;
        }
        else if(arr[right]<arr[left])
        {
            arr[index]=arr[right];
            index=right;
        }
        else
        {
            arr[index]=arr[left];
            index=left;
        }
        left=2*index;
        right=left+1;
    }
    //if the number of nodes is even then..
    if(left==h_size&&val>arr[left])
    {
        arr[index]=arr[left];
        index=left;
    }
    arr[index]=val;
}
int deletion()
{
    if(num==0)
        return -1;//to indicate that there are no more elements remaining in the heap..:)
    int maxx=arr[1];
    arr[1]=arr[num];
    num=num-1;
    restore_down(1,num);
    return maxx;
}

