/*this question is also good as it uses bitmasking and dynamic programming concept*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> arr(35);
int main()
{
    ll test,i,j,num,ans;
    arr[0]=1,arr[1]=0,arr[2]=3,arr[3]=0;
    for(i=4;i<31;i++)
    {
        if(i%2==0)
            arr[i]=4*arr[i-2]-arr[i-4];
        else
            arr[i]=0;
    }
    while(1)
    {
        scanf("%lld",&num);
        if(num==(-1))
            break;
        printf("%lld\n",arr[num]);
    }
}

