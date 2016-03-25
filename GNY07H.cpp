/*this question is advanced type in dynamic programming.and it is the best problem*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> arr(35);
int main()
{
    ll test,i,j,a,b,num;
    scanf("%lld",&test);
    arr[0]=1,arr[1]=1,arr[2]=5,arr[3]=11,arr[4]=36,arr[5]=95,arr[6]=281;
    for(i=7;i<=34;i++)
        arr[i]=arr[i-1]+5*arr[i-2]+arr[i-3]-arr[i-4];
    for(i=1;i<=test;i++)
    {
        scanf("%lld",&num);
        printf("%lld %lld\n",i,arr[num]);
    }
}

