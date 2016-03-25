#include<stdio.h>
#define maxx 100
void display(int mat[maxx][maxx],int n);
int adj[maxx][maxx];
int n;
void create_graph();
int main()
{
    int i,j,k;
    int p[maxx][maxx];
    create_graph();
    printf("\nthe adjacency matrix is as:");
    display(adj,n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        p[i][j]=adj[i][j];
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            p[i][j]=(p[i][j]||(p[i][k]&&p[k][j]));
        printf("\np%d is as:\n",k);
        display(p,n);
    }
    printf("\np%d is the path matrix:",k-1);
}

void display(int mat[maxx][maxx],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
}

void create_graph()
{
    int i,j,origin,destin,max_edges;
    printf("enter the total number of edges:");
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
