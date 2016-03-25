#include<stdio.h>
#include<stdlib.h>
#define maxx 100
#define nil -1
#define initial 1
#define visited 2
int n;
int adj[maxx][maxx];
void push_stack(int i);
int pop_stack();
int stack_empty();
int stack_full();
int state[maxx];
int predecessor[maxx];
int dfs_stack[maxx];
void create_graph();
void df_traversal();
void dfs(int v);
int top=-1;
int main()
{
    create_graph();
    df_traversal();
}

void df_traversal()
{
    int v;
    char ch;
    for(v=0;v<n;v++)
       {
         state[v]=initial;
         predecessor[v]=nil;
       }
    printf("enter the vertex from which u want to start traversing:");
    scanf("%d",&v);
    dfs(v);
    printf("\ndo u want complete traversal or not:if yes enter y:");
    scanf("%c",&ch);
    if(ch=='y')
    {
        for(v=0;v<n;v++)
        {
            if(state[v]==initial)
                dfs(v);
        }
    }
    printf("\n");
    for(v=0;v<n;v++)
      printf("\nvertex %d predecessor %d",v,predecessor[v]);
    printf("\ntree edges:");
    for(v=0;v<n;v++)
        if(predecessor[v]!=-1)
         printf("\ntree edge:%d->%d",predecessor[v],v);
}

void dfs(int v)
{
    int i;
    push_stack(v);
    while(!stack_empty())
    {
        v=pop_stack();
        if(state[v]==initial)
        {
            printf("%d ",v);
            state[v]=visited;
        }
        for(i=n-1;i>=0;i--)
            if(state[i]==initial&&adj[v][i]==1)
              push_stack(i);
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

void push_stack(int i)
{
    if(top==maxx-1)
    {
        printf("\nstack overflow condition is occur:");
        return;
    }
    top=top+1;
    dfs_stack[top]=i;
}

int pop_stack()
{
    int v;
    if(top==-1)
    {
        printf("\nstack underflow condition occurs:");
        exit(1);
    }
    else
    {
        v=dfs_stack[top];
        top=top-1;
    }
}

int stack_empty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int stack_full()
{
    if(top==maxx-1)
        return 1;
    else
        return 0;
}
