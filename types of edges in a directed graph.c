#include<stdio.h>
#include<stdlib.h>
#define maxx 100
#define nil -1
#define initial 1
#define visited 2
#define finished 3
int n;
int time;
int f[maxx];
int adj[maxx][maxx];
int state[maxx];
int predecessor[maxx];
int d[maxx];
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
    time++;
    d[v]=time;
    state[v]=visited;
    for(i=0;i<n;i++)
    {
        if(adj[v][i]==1)
        {
            if(state[i]==initial)
            {
                printf("\ntree edge:%d %d",v,i);
                dfs(i);
            }
            else if(state[i]==visited)
            {
                printf("back edge:%d %d ",v,i);
            }
            else if(d[v]<d[i])
            {
                printf("(%d %d):forward edge:",v,i);
            }
            else
                printf("(%d %d):cross edge:",v,i);
        }
    }
    state[v]=finished;
    f[v]=++time;
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


