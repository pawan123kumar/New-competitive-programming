//basically we can see,this builds up the heap in the bottom up order..so the heap is to be constructed in O(n)...
//the basic concept behind this heap building by bottom up is that...during this we first find out first non-leaf node which,
//has 0,1,or 2 childs....this is from the complete binary tree
//0 or 2 childs when number of elements are odds and 1 child if  number of elements are even..
//during bottom up it creates heap of size 1 then 2 ...and so on ..and we see that basically,it recursively creates the heap from
//last level of complete binary tree...then second last..then third last..and so on..
//so finally we can say time complexity for building heap is O(n)...
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
    int right=index*2+1;
    while(right<=h_size)
    {
        if(val>=arr[left]&&val>=arr[right])
        {
            arr[index]=val;
            return;
        }
        else if(arr[right]>arr[left])
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
        right=2*index+1;
    }
    //if the number of nodes is even then..
    if(left==h_size&&val<arr[left])
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
/*void restore_up(int i)
{
    ll temp=arr[i];
    int par=i/2;
    while(par>=1&&arr[par]<temp)
    {
        arr[i]=arr[par];
        i=i/2;
        par=i/2;
    }
    arr[i]=temp;
}*/ //this may be used when heap is build up in top down manner..means we are inserting elements one by one from the array

