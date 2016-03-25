#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct weight_val
{
    ll weight;
    ll val;
};
struct weight_val arr[1001];
ll mat[1001][1001];
ll find_num_items(ll num,ll weight)
{
    for(ll i=0;i<=num;i++)
    {
        for(ll j=0;j<=weight;j++)
        {
            if((i==0)||(j==0))
                mat[i][j]=0;
            else if((j-arr[i].weight)>=0)
                mat[i][j]=max(mat[i-1][j],arr[i].val+mat[i-1][j-arr[i].weight]);
            else
                mat[i][j]=mat[i-1][j];
        }
    }
    return mat[num][weight];
}
int main()
{
    ll i,j,num,maxx,minn,a,b,c,weight;
    ll flag1,flag2,test;
    cin>>test;
    while(test--)
    {
        cin>>num>>weight;
        for(i=1;i<=num;i++)
            cin>>arr[i].weight>>arr[i].val;
        flag1=find_num_items(num,weight);
        cout<<flag1<<endl;
    }
}

