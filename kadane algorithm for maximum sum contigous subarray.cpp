//complexity here is O(n)...:)
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define sc1(x) scanf("%lld",&x)
vector<ll> arr(100001);
void kadane_algo(ll num)
{
    ll curr_maxx=arr[0],maxx_so_far=arr[0];
    for(ll i=1;i<num;i++)
    {
        curr_maxx=max(arr[i],curr_maxx+arr[i]);
        maxx_so_far=max(curr_maxx,maxx_so_far);
    }
    cout<<maxx_so_far<<endl;
}
int main()
{
    ll test,i,j,ans,total,curr_maxx,maxx_so_far,num;
    sc1(test);
    while(test--)
    {
        sc1(num);
        for(i=0;i<num;i++)
            sc1(arr[i]);
        kadane_algo(num);
    }
}

