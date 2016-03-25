//in this we have to find out that we can equally divide the array_sum or not....
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector< vector<bool> > table(100001,vector<bool>(201));
vector<ll> arr(201);
bool partition_equal(ll num,ll sum)
{
    for(ll i=0;i<=num;i++)//as sum 0 can be achieveable without any element
        table[0][i]=true;
    for(ll i=1;i<=sum/2;i++)//sum 1,2,3...cannot be achieveable,if there is  no element
        table[i][0]=false;
    for(ll i=1;i<=sum/2;i++)
    {
        for(ll j=1;j<=num;j++)
        {
            table[i][j]=table[i][j-1];//this element may not contribute into sum=i,because if sum=i may be already made by previous elements
            if(i>=arr[j-1])
                table[i][j]=table[i][j-1]||table[i-arr[j-1]][j-1];
        }
    }
    return table[sum/2][num];
}
int main()
{
    ll a,b,test,i,j,minn,maxx,sum,num;
    scanf("%lld",&test);
    while(test--)
    {
        sum=0;
        scanf("%lld",&num);
        for(ll i=0;i<num;i++)
        {
            scanf("%lld",&arr[i]);
            sum+=arr[i];
        }
        if(sum%2)//if sum is odd then there is no chance for equal division
            printf("NO\n");
        else
        {
            if(partition_equal(num,sum))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}

