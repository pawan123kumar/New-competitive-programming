#include<stdio.h>
#include<stdlib.h>
#define maxx 100
#define initial 1
#define waiting 2
#define visited 3
int state[maxx];
int n;
int adj[maxx][maxx];
int label[maxx];
void create_graph();
void bf_traversal();
void bfs(int v,int component_num);
void insert_queue(int vertex);
int del_queue();
int queue_empty();
int que[maxx],frontt=-1,rear=-1;
int main()
{
    create_graph();
    bf_traversal();
}

void create_graph()
{
    int origin,destin,i,max_edges;
    printf("enter the total no. of vertices:");
    scanf("%d",&n);
    max_edges=n*(n-1);
    for(i=1;i<=max_edges;i++)
    {
        printf("\nenter the origin and destination(-1 -1 to quit):");
        scanf("%d%d",&origin,&destin);
        if(origin==-1&&destin==-1)
            break;
        if(origin<0||destin<0||origin>=n||destin>=n)
        {
            printf("\nthe vertices entered are wrong:");
            i--;
        }
        else
            adj[origin][destin]=1;
    }
}

void bf_traversal()
{
    int v,components=0;
    for(v=0;v<n;v++)
      state[v]=initial;
    components++;
    bfs(0,components);//starting bfs from 0 vertex
    for(v=0;v<n;v++)
    {
        if(state[v]==initial)
        {
            components++;
            bfs(v,components);
        }
    }
    printf("the number of connected components are as:",components);
    if(components==1)
        printf("\nthe graph is connected:");
    else
        printf("the graph is not connected:");
}

void bfs(int v,int component_num)
{
    int i;
    insert_queue(v);
    state[v]=waiting;
    while(!queue_empty())
    {
        v=del_queue();
        state[v]=visited;
        label[v]=component_num;
        printf("\nvertex %d  component=%d",v,label[v]);
        for(i=0;i<n;i++)
        {
            if(adj[v][i]==1&&state[i]==initial)
            {
                insert_queue(i);
                state[i]=waiting;
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
