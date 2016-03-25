#include<bits/stdc++.h>
#define ll long long int
using namespace std;
long long int arr[100000];
void build_heap(ll num);
void display_heap(int num);
void insert_in_heap(ll *hsize,ll val);
ll del_from_heap(ll *hsize);
void restore_up(ll i);
void restore_down(ll i,ll hsize);
int main()
{
    long long int num,test,n,i,j;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&num);
        for(i=1;i<=num;i++)
            scanf("%lld",&arr[i]);
        build_heap(num);
        display_heap(num);
    }
}
void insert_in_heap(ll *hsize,ll val)
{
    arr[++*hsize]=val;
    restore_up(*hsize);
}
ll del_from_heap(ll *hsize)
{
    ll maxx=arr[1];
    arr[1]=arr[*hsize];
    *hsize--;
    restore_down(1,*hsize);
    return maxx;
}
void build_heap(ll num)
{
    ll i;
    for(i=num/2;i>=1;i--)
        restore_down(i,num);
}
void restore_up(ll i)
{
    ll k=arr[i];
    ll par=i/2;
    while(par>=1 && arr[par]<k)
    {
        arr[i]=arr[par];
        i=par;
        par=i/2;
    }
    arr[i]=k;
}
void restore_down(ll i,ll hsize)
{
    ll lchild=2*i;
    ll rchild=2*i+1;
    ll num=arr[i];
    while(rchild<=hsize)
    {
        if(num>=arr[lchild]&&num>=arr[rchild])
        {
            arr[i]=num;
            return;
        }
        else if(arr[lchild]>arr[rchild])
        {
            arr[i]=arr[lchild];
            i=lchild;
        }
        else
        {
            arr[i]=arr[rchild];
            i=rchild;
        }
        lchild=2*i;
        rchild=lchild+1;
    }
    if(lchild==hsize&&num<arr[lchild])//if number of nodes is even
    {
        arr[i]=arr[lchild];
        i=lchild;
    }
    arr[i]=num;
}
void display_heap(int num)
{
    printf("elements in the heap are as:");
    for(ll i=1;i<=num;i++)
        printf("%lld ",arr[i]);
}

