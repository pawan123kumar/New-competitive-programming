//the problem consists of n wine bottles orderly arranged..we know wine is getting better as old it becomes...
//so now we have given bottles prizes as in order as bottles are being arranged...
//after m years,rate of that bottle is becmoes increased by m*rate..
//now we have to sold all of the bottles in order to get maximum profit...
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll> > table(1000,vector<ll>(1000,-1));
vector<ll> arr(1000);
ll num;
ll get_max_profit(ll start,ll endd)
{
  if(start>endd)
        return 0;
  if(table[start][endd]!=-1)
    return table[start][endd];
  ll year=num-(endd-start+1)+1;
  return table[start][endd]=max(get_max_profit(start,endd-1)+arr[endd]*year,get_max_profit(start+1,endd)+arr[start]*year);
}
int main()
{
    int test;
    scanf("%lld",&num);
    for(int i=0;i<num;i++)
        scanf("%lld",&arr[i]);
    printf("the maximum profit we can get from wines is :%lld",get_max_profit(0,num-1));
}

