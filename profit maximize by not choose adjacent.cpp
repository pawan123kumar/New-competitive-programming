#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll num,i,j,test;
    scanf("%lld",&test);
    vector<ll> arr(100001);
    vector<ll> status(100001);
    while(test--)
    {
    scanf("%lld",&num);
    for(i=0;i<num;i++)
        scanf("%lld",&arr[i]);
    if(num==1)
        printf("%lld",arr[0]);
    else if(num==2)
        printf("%lld",max(arr[0],arr[1]));
    else if(num==3)
        printf("%lld",max(arr[0]+arr[2],arr[1]));
    else
    {
        status[0]=arr[0];
        status[1]=max(arr[0],arr[1]);
        status[2]=max(arr[0]+arr[2],arr[1]);
        for(i=3;i<num;i++)
        {
            if(status[i-2]+arr[i]>status[i-1])
                status[i]=arr[i]+status[i-2];
            else
                status[i]=status[i-1];
        }
        printf("%lld",status[num-1]);
    }
    }
}

