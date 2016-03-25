#include<stdio.h>
#include<stdlib.h>
#define maxx 100
#define nil -1
#define initial 1
#define visited 2
#define finished 3
int n;
int time=0;
int adj[maxx][maxx];
int discovery_time[maxx];
int finished_time[maxx];
int state[maxx];
int predecessor[maxx];
void create_graph();
void df_traversal();
void dfs(int v);
void print_timing();
int main()
{
    create_graph();
    df_traversal();
    print_timing();
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
    time++;
    discovery_time[v]=time;//this is the discovery time of the vertex
    state[v]=visited;
    for(i=0;i<n;i++)
    {
        if(adj[v][i]==1&&state[i]==initial)
            dfs(i);
    }
    state[v]=finished;
    finished_time[v]=++time;//finishing time
}

void print_timing()
{
    for(int i=0;i<n;i++)
    {
        printf("\ndiscovery time of %d is :%d ",i,discovery_time[i]);
        printf("and finished time is :%d",finished_time[i]);
    }
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



