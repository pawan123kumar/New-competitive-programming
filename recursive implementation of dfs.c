#include<stdio.h>
#include<stdlib.h>
#define maxx 100
#define nil -1
#define initial 1
#define visited 2
#define finished 3
int n;
int adj[maxx][maxx];
int state[maxx];
int predecessor[maxx];
void create_graph();
void df_traversal();
void dfs(int v);
int main()
{
    create_graph();
    df_traversal();
}

void df_traversal()
{
    int v;
    for(v=0;v<n;v++)
        state[v]=initial;
    printf("enter starting vertex for dfs:");
    scanf("%d",&v);
    dfs(v);
    for(v=0;v<n;v++)
    {
        if(state[v]==initial)
            dfs(v);
    }
    printf("\n");
}

void dfs(int v)
{
    int i;
    printf("%d ",v);
    state[v]=visited;
    for(i=0;i<n;i++)
    {
        if(adj[v][i]==1&&state[i]==initial)
            dfs(i);
    }
    state[v]=finished;
}

void create_graph()
{
    int i,max_edges,origin,destin;
    printf("\nenter the total number of edges:");
    scanf("%d",&n);
    max_edges=n*(n-1);
    for(i=1;i<=max_edges;i++)
    {
        printf("\nenter the origin and destination:");
        scanf("%d%d",&origin,&destin);
        if(origin==-1&&destin==-1)
            break;
        if(origin<0||destin<0||origin>=n||destin>=n)
        {
            printf("\nplez enter the valid indices:");
            i--;
        }
        else
            adj[origin][destin]=1;
    }
}

