//it prints the path according the item included.
#include<bits/stdc++.h>
using namespace std;
#define ll long long  int
struct node
{
    ll val;
    ll wt;
};
vector<struct node> arr(1001);
vector< vector<ll> > dp_table(1001,vector<ll>(1001));
void find_knapsack_value(ll num,ll weight)
{
    vector<ll> print_arr;
    vector< vector<bool> > pick(num+1,vector<bool>(weight+1,false));
    for(ll i=0;i<=num;i++)//for items
    {
        for(ll w=0;w<=weight;w++)//for the weight value
        {
            if(i==0||w==0)
                dp_table[i][w]=0;
            else if(arr[i-1].wt<=w)
            {
                if(dp_table[i-1][w]>(arr[i-1].val+dp_table[i-1][w-arr[i-1].wt]));
                    pick[i][w]=true;
                dp_table[i][w]=max(dp_table[i-1][w],(arr[i-1].val+dp_table[i-1][w-arr[i-1].wt]));//if the value is to be included
            }
            else
                dp_table[i][w]=dp_table[i-1][w];//if the weight is  not included...:)
        }
    }
    ll t=weight;
    for(ll i = num;i>=0;i--)
    {
        if(pick[i][t]==true)
        {
            cout<<i<<" ";
            t-=arr[i-1].wt;
        }
  }
    vector<ll>::iterator itr;
    for(itr=print_arr.begin();itr!=print_arr.end();itr++)
        cout<<*itr<<" ";
    cout<<endl<<"final weight is as: ";
    cout<<dp_table[num][weight]<<endl;
}
int main()
{
    ll a,b,maxx,minn,test,num,weight;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld%lld",&num,&weight);
        printf("enter the corresponding weights and values:");
        for(ll i=0;i<num;i++)
            cin>>arr[i].wt>>arr[i].val;
        find_knapsack_value(num,weight);
    }
}

