#include<cstdio>
#include<cstdlib>
#include<iostream>
#define maxx 5000
#define infinity 9999
#define nil -1
//void find_path(int s,int v);
int adj[maxx][maxx];
int D[maxx][maxx];
int predecessor[maxx][maxx];
void floyd_warshalls();
void create_graph();
//void display(int mat[maxx][maxx],int n);
//void find_short_path(int s,int v);
int n;
void initialize();
int main()
{
    int s,v,destin;
    create_graph();
    floyd_warshalls();
    int queries;
    scanf("%d",&queries);
    for(int i=0;i<queries;i++)
    {
        scanf("%d%d",&s,&v);
        if(D[s-1][v-1]==infinity)
            printf("No Connection\n");
        else if(D[s-1][v-1]==1)
            printf("Direct Connection\n");
           // printf("Direct Connection\n");
        else
            printf("Indirect Connection\n");

    }
}
void create_graph()
{
    int num;
    int source,destin,weight;
    initialize();
    //printf("enter the total number of vertices:");
    scanf("%d",&n);
    int total_edges;
    scanf("%d",&total_edges);
    for(int i=0;i<total_edges;i++)
    {
        //printf("enter source,destination,weight:");
        scanf("%d%d",&source,&destin);
            adj[source-1][destin-1]=1;
    }
}
void initialize()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            adj[i][j]=0;
        }
    }
}
void floyd_warshalls()
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(adj[i][j]==0)
            {
                D[i][j]=infinity;
                predecessor[i][j]=-1;
            }
            else
            {
                D[i][j]=adj[i][j];
                predecessor[i][j]=i;
            }
        }
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(D[i][k]+D[k][j]<D[i][j])
                {
                    D[i][j]=D[i][k]+D[k][j];
                    predecessor[i][j]=predecessor[k][j];
                }
            }
        }
    }
    /*printf("shortest path matrix is as:");
    display(D,n);
    printf("predecessor matrix is as:");
    display(predecessor,n);
    for(i=0;i<n;i++)
        if(D[i][i]<0)
        {
            printf("graph contains a negative cycle:");
            exit(1);
        }*/
}
/*void find_short_path(int s,int v)
{
    int destin=v,current=-1;
    if(D[s][v]==infinity)
    {
        printf("there is no path exists:");
        return;
    }
    int path[maxx];
    do
    {
        path[++current]=v;
        v=predecessor[s][v];
    }while(v!=s);
    printf("\nshortest distance between %d and %d is as:%d",s,destin,D[s][destin]);
    printf("\nshortest path is as:");
    for(int i=current;i>=0;i--)
        printf("%d ",path[i]);
    printf("\n");
}*/
/*void display(int mat[maxx][maxx],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}*/


