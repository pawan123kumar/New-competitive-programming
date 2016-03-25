#include<stdio.h>
#include<stdlib.h>
#define maxx 100
#define initial 1
#define waiting 2
#define visited 3
void create_graph();
void traverse_graph();
void bfs(int v);
int que[maxx],rear=-1,frontt=-1;
int queue_empty();
int queue_full();
void insert_queue(int a);
int del_queue();
int adj[maxx][maxx];
int state[maxx];
int n;
int main()
{
    create_graph();
    traverse_graph();
}

void create_graph()
{
    int i,max_edges,origin,destin;
    printf("\nenter the total number of vertices:");
    scanf("%d",&n);
    max_edges=(n*(n-1))/2;
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
            {
                adj[origin][destin]=1;
                adj[destin][origin]=1;
            }
    }
}

void traverse_graph()
{
    int i,v;
    char ch='y';
    for(i=0;i<n;i++)
        state[i]=initial;
    printf("\nenter vertex from which u want to traverse graph:");
    scanf("%d",&v);
    bfs(v);
    /*printf("\nenter 'y' to traverse whole of graph else enter 'n'");//this is for the directed graph
    scanf("%c",&ch);
    if(ch=='y')
    {
       for(i=0;i<n;i++)
        if(state[i]==initial)
         bfs(i);
    }*/
    int flag=0;
    for(i=0;i<n;i++)
    {
        if(state[i]==initial)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        printf("\nthe given undirected graph is not connected:");
    else
        printf("\nthe given undirected graph is connected:");
}

void bfs(int v)
{
    int i,j;
    insert_queue(v);
    state[v]=waiting;
    while(!queue_empty())
    {
        i=del_queue();
        printf("%d ",i);
        state[i]=visited;
        for(j=0;j<n;j++)
        {
            //checking for adjacent vertices
            if(state[j]==initial&&adj[i][j]==1)
            {
                insert_queue(j);
                state[j]=waiting;
            }
        }
    }
}

int del_queue()
{
    int a;
    if(queue_empty())
    {
        printf("\nqueue is in the underflow condtion:");
        exit(1);
    }
    a=que[frontt];
    frontt=frontt+1;
    return a;
}

void insert_queue(int v)
{
    if(rear==maxx-1)
    {
        printf("\nthe queue is in overflow condition:");
        return;
    }
    else
    {
        if(frontt==-1)
            frontt=0;
        rear=rear+1;
        que[rear]=v;
    }

}

int queue_empty()
{
    if(frontt==-1||frontt>rear)
        return 1;
    else
        return 0;
}

