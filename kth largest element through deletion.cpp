#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[100000];
void build_heap(ll num);
void display_heap(ll num);
void insert_in_heap(ll *hsize,ll val);
ll del_from_heap(ll hsize);
void restore_up(ll i);
void restore_down(ll i,ll hsize);
//ll heap_sort(ll num,ll k);
void copy_heap_arr(ll num);
ll copy_arr[100000];
int main()
{
    ll p=1,val,test,n,i,j,num,k;
    ll total_nums,kth_large,ele,q=1;
    scanf("%lld",&test);
    while(test--)
    {
        //total_nums=&p;
        scanf("%lld",&num);
        for(i=1;i<=num;i++)
            scanf("%lld",&arr[i]);
        build_heap(num);
        copy_heap_arr(num);
        scanf("%lld",&k);
        //printf("\nelements in max sorted order are as:");
        //kth_large=heap_sort(num,k);
        if(k>num)
            printf("\nthere is no kth largest element:");
        else
        {
            total_nums=num;
            for(i=0;i<k;i++)
            {
                q=1;
                ele=del_from_heap(total_nums);
            }
            printf("\n%lld is %lld largest element:",ele,k);
        }
        display_heap(num);
    }
}
void copy_heap_arr(ll num)
{
    for(ll i=1;i<=num;i++)
        copy_arr[i]=arr[i];
}
/*ll heap_sort(ll num,ll k)
{
    if(num==0)//base case
        return -1;
    else if(k>num)
        return -1;
    else if(k==1)
        return arr[1];
    else
    {
        swap(arr[1],arr[num]);
        restore_down(1,num-1);
        return heap_sort(num-1,k-1);
    }
}*/
void insert_in_heap(ll *hsize,ll val)
{
    arr[++*hsize]=val;
    restore_up(*hsize);
}
ll del_from_heap(ll hsize)
{
    ll maxx=arr[1];
    arr[1]=arr[hsize];
    hsize--;
    restore_down(1,hsize);
    return maxx;
}
void build_heap(ll num)
{
    ll i;
    for(i=(num/2);i>=1;i--)
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
void display_heap(ll num)
{
    printf("\nelements in the heap are as:");
    for(ll i=1;i<=num;i++)
        printf("%lld ",copy_arr[i]);
}



