//here we have to find the longest bitonic subsequence...which is increasing as well as non-decreasing......:)
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define sc(x) scanf("%lld",&x)
vector<ll> arr(100001);
vector<ll> table_inc(100001);
vector<ll> table_dec(100001);
void longest_bitonic_sequence(ll num)
{
    ll i,j,total,maxx=1;
    table_inc[0]=1;
    for(i=1;i<num;i++)//here it is only for increasing subsequence
    {
        table_inc[i]=1;
        for(j=0;j<i;j++)
        {
            if( (arr[i]>arr[j]) && ( (table_inc[j]+1)>table_inc[i]) )
                table_inc[i]=1+table_inc[j];
        }
        //maxx=max(table_inc[i],maxx);
    }
    //cout<<maxx<<endl;
    table_dec[num-1]=1;
    for(i=num-2;i>=0;i--)//here it is for incresing subsequence from right..means decresing subsequence from left....:)
    {
        table_dec[i]=1;
        for(j=num-1;j>i;j--)
        {
            if( (arr[i]>arr[j]) && ( (table_dec[j]+1)>table_dec[i]) )
                table_dec[i]=1+table_dec[j];
        }
    }
    for(i=0;i<num;i++)//here maximum sum tells us the bitonic sub_sequence
        maxx=max(maxx,table_dec[i]+table_inc[i]-1);
    cout<<maxx<<endl;
}
int main()
{
    ll a,i,j,test,num;
    sc(test);
    while(test--)
    {
        sc(num);
        for(i=0;i<num;i++)
            sc(arr[i]);
        longest_bitonic_sequence(num);
    }
}

