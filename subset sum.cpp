#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> arr(51);
bool subset_sum(ll set_arr[],ll index,ll i,ll num,ll sum)
{
    if(i>num)
        return false;
    if(i==num)
    {
        ll ans=0;
        for(ll j=0;j<index;j++)
            ans+=set_arr[j];
        if(ans==sum)
        {
            for(ll j=0;j<index;j++)//it will print the subset which contains the corresponding sum
                cout<<set_arr[j]<<" ";
            return true;
        }
        else
            return false;
    }
    else
    {
        set_arr[index]=arr[i];
        if(subset_sum(set_arr,index+1,i+1,num,sum))
            return true;
        else
            return subset_sum(set_arr,index,i+1,num,sum);
    }
}
int main()
{
    ll set_arr[51];
    ll test,i,j,num,sum;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&num);
        for(i=0;i<num;i++)
            scanf("%lld",&arr[i]);
        scanf("%lld",&sum);
        if(subset_sum(set_arr,0,0,num,sum))
            printf("\nYES\n");
        else
            printf("NO\n");
    }
}

