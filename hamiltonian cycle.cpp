#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector< vector<ll> > graph(101,vector<ll>(101));
ll path[101];
void initialize(ll num)
{
    for(ll i=0;i<num;i++)
    {
        path[i]=-1;
        for(ll j=0;j<num;j++)
            graph[i][j]=0;
    }
}
bool safe_path(ll v,ll path[],ll num,ll pos)
{
    if(graph[path[pos-1]][v]==0)//it means if there is no edge to previously added vertex..means it can't be added
        return false;
    for(ll i=0;i<pos;i++)
    {
        if(path[i]==v)
            return false;//it means there is already vertex,v is included
    }
    return true;
}
bool find_ham_cycle(ll path[],ll num,ll pos)
{
    if(pos==num)
    {
        if(graph[path[pos-1]][path[0]]==1)//means there is a path from initial to final and final to initial
            return true;
        else
            return false;
    }

    for(ll i=0;i<num;i++)
    {
        if(safe_path(i,path,num,pos))
        {
            path[pos]=i;
            if(find_ham_cycle(path,num,pos+1))
                return true;
            path[pos]=-1;//if the added vertex,i doesn't lead to a solution, Backtrack it
        }
    }
    return false;//it means no path is to be selected
}
int main()
{
    ll src,pos,m,test,a,b,i,j,num;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld%lld",&num,&m);
        initialize(num);
        for(i=0;i<m;i++)
        {
            scanf("%lld%lld",&a,&b);
            graph[a][b]=1;//it means there is a path exists between a and b
            graph[b][a]=1;
        }
        pos=0;
        scanf("%lld",&src);
        path[pos++]=src;//it means 0th vertex added is 0
        if(find_ham_cycle(path,num,pos))
        {
            printf("there exists hamiltonian cycle:\t");
            printf("path is as: ");
            for(i=0;i<num;i++)
                printf("%lld ",path[i]);
            printf("%lld\n",path[0]);
        }
        else
            printf("there is not any hamiltonian cycle:\n");
    }
}

