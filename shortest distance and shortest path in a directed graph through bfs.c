#include<stdio.h>
#include<stdlib.h>
#define maxx 100
#define infinite 9999
#define nil -1
#define initial 1
#define waiting 2
#define visited 3
int n;
int adj[maxx][maxx];
int state[maxx];
int distance[maxx];
int predecessor[maxx];
void create_graph();
void bf_traversal();
void bfs(int v);
int que[maxx],front=-1,rear=-1;
void insert_queue(int vertex);
int del_queue();
int queue_empty();

main()
{
    int u,v,i,count,path[maxx];
    create_graph();
    bf_traversal();
    while(1)
    {
        printf("\nenter the destination vertex:");
        scanf("%d",&v);
        if(v<-1||v>=n)
        {
            printf("\ndestination vertex is not exist:");
            continue;
        }
        if(v==-1)
            break;
        count=0;
        if(distance[v]==infinite)
        {
            printf("\ndestination vertex is not reachable:");
            continue;
        }
        else
            printf("\nshortest distance is as:%d",distance[v]);
        /*to show the full shortest path*/
        while(v!=nil)
        {
            count++;
            path[count]=v;
            v=predecessor[u];
            u=v;
        }
        printf("\nthe shortest path is as:");
        for(i=count;i>1;i++)
            printf("%d ",path[i]);
        printf("%d\n",path[i]);
    }
}


void bf_traversal()
{
    int v;
    for(v=0;v<n;v++)
    {
        state[v]=initial;
        predecessor[v]=nil;
        distance[v]=infinite;
    }
    printf("\nenter the starting vertex for bfs:");
    scanf("%d",&v);
    bfs(v);
}

void bfs(int v)
{
    int i;
    insert_queue(v);
    state[v]=waiting;
    distance[v]=0;
    predecessor[v]=nil;
    while(!queue_empty())
    {
        v=del_queue();
        state[v]=visited;
        printf("%d ",v);
        for(i=0;i<n;i++)
        {
            /*check for adjacent unvisited vertices*/
            if(adj[v][i]==1&&state[i]==initial)
            {
                insert_queue(i);
                state[i]=waiting;
                predecessor[i]=v;
                distance[i]=distance[v]+1;
            }
        }
    }
}

void create_graph()
{
    int i,j,origin,destin,max_edges;
    printf("enter the total number of vertices:");
    scanf("%d",&n);
    max_edges=n*(n-1);
    for(i=1;i<=max_edges;i++)
    {
        printf("\nenter origin and destination:(-1 -1 to quit:)");
        scanf("%d%d",&origin,&destin);
        if(origin==-1&&destin==-1)
            break;
        if(origin<0||destin<0||origin>=n||destin>=n)
        {
            printf("the entered edge is not correct:");
            i--;
        }
        else
            adj[origin][destin]=1;
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
    a=que[front];
    front=front+1;
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
        if(front==-1)
            front=0;
        rear=rear+1;
        que[rear]=v;
    }

}

int queue_empty()
{
    if(front==-1||front>rear)
        return 1;
    else
        return 0;
}

/*for all of the tree edges
void bfs(int v)
{
    int i;
    insert_queue(v);
    predecessor[v]=nil;
    distance[v]=0;
    while(!isempty_queue())
    {
        v=delete_queue();
        printf("%d ",v);
        state[v]=visited;
        for(i=0;i<n;i++)
        {
            if(adj[v][i]==1&&state[i]==initial)
            {
                insert_queue[i];
                state[i]=waiting;
                printf("---tree edge is :(%d %d)",v,i);
            }
        }
    }
}*/

