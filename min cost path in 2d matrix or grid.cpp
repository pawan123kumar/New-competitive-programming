#include<bits/stdc++.h>
using namespace std;
long long int cost[101][101];
int num;
long long int compute_min_cost_path()
{
    for(int i=1;i<num;i++)
    {
        cost[0][i]+=cost[0][i-1];//initialize path only in row1..means travel only in 00,01,02,03
        cost[i][0]+=cost[i-1][0];//initialize path only in column1..means travel only in 00,10,20,30
    }
    for(int i=1;i<num;i++)
    {
        for(int j=1;j<num;j++)
        {
            cost[i][j]=min(cost[i-1][j],cost[i][j-1])+cost[i][j];//this computes the minimum cost by select from upward pathand back path
        }
    }
    return cost[num-1][num-1];
}
int main()
{
    long long int min_cost;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
        for(int j=0;j<num;j++)
        scanf("%lld",&cost[i][j]);//store the cost for each path
    min_cost=compute_min_cost_path();
    printf("the minimum cost in travlling the path is %lld",min_cost);
}

