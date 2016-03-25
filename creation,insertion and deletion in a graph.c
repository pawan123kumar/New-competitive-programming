#include<stdio.h>
#include<stdlib.h>
#define maxx 100
int adj[maxx][maxx];
int n;
void create_graph();
void display();
void insert_edge(int origin,int destin);
void del_edge(int origin,int destin);

main()
{
    int choice,origin,destin;
    create_graph();
    while(1)
    {
        printf("\n1.insert an edge:");
        printf("\n2.delete an edge:");
        printf("\n3.display the adjacency matrix:");
        printf("\n4exit");
        printf("\nenter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nenter an edge to be inserted:");
            scanf("%d%d",&origin,&destin);
            insert_edge(origin,destin);
            break;
        case 2:
            printf("\nenter an edge to be deleted:");
            scanf("%d%d",&origin,&destin);
            del_edge(origin,destin);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("please enter the valid choice:");
        }
    }
}

void create_graph()
{
    int i,max_edges,n,origin,destin;
    printf("enter the number of vertices:");
    scanf("%d",&n);
    max_edges=n*(n-1);
    for(i=1;i<=max_edges;i++)
    {
        printf("enter edge (-1 -1)to quit:");
        scanf("%d%d",&origin,&destin);
        if(origin==-1&&destin==-1)
            break;
        if(origin>=n||destin>=n||origin<0||destin<0)
        {
            printf("\ninvalid edge:");
            i--;
        }
        else
            adj[origin][destin]=1;
    }
}

void insert_edge(int origin,int destin)
{
    if(origin<0||origin>=0)
    {
        printf("origin vertex does not exist:");
        return;
    }
    if(destin<0||destin>=n)
    {
        printf("destination vertex not exist:");
        return;
    }
    adj[origin][destin]=1;
}

void del_edge(int origin,int destin)
{
    if(origin<0||origin>=n||destin<0||origin>=n||adj[origin][destin]==0)
    {
        printf("this edge does not exist:");
        return;
    }
    adj[origin][destin]=0;
}

void display()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",adj[i][j]);
        printf("\n");
    }
}
