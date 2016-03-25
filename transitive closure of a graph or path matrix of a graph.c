#include<stdio.h>
#define maxx 100
void display(int arr[maxx][maxx],int n);
void pow_matrix(int p,int adjp[maxx][maxx]);
void multiply(int mat1[maxx][maxx],int mat2[maxx][maxx],int mat3[maxx][maxx]);
void create_graph();
int adj[maxx][maxx];
int n;
int main()
{
    int adjp[maxx][maxx];
    int i,x[maxx][maxx],path[maxx][maxx],j,p;
    create_graph();
    printf("\nthe adjacency matrix is as:\n");
    display(adj,n);
    //initialize all elements of x to zero:
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        x[i][j]=0;
    //all the powers of adj will be added to matrix x
    for(p=1;p<=n;p++)
    {
        pow_matrix(p,adjp);
        printf("adjacency matrix raised to power %d is -\n",p);
        display(adjp,n);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            x[i][j]=x[i][j]+adjp[i][j];
    }
    printf("the matrix is as:\n");
    display(x,n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
         if(x[i][j]==0)
          path[i][j]=0;
         else
          path[i][j]=1;
    printf("the path matrix is as:\n");
    display(path,n);
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

void pow_matrix(int p,int adjp[maxx][maxx])
{
    int i,j,k,tmp[maxx][maxx];
    //initially we assume that adjp is equal to adj
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        adjp[i][j]=adj[i][j];
    for(k=1;k<p;k++)
    {
        //multiply adjp with adj and store the result in tmp
        multiply(adjp,adj,tmp);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            adjp[i][j]=tmp[i][j];
    }
}

void multiply(int mat1[maxx][maxx],int mat2[maxx][maxx],int mat3[maxx][maxx])
{
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
                mat3[i][j]=mat1[i][k]*mat2[k][j];
        }
}

void display(int arr[maxx][maxx],int n)
{
    int i,j;
    for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
             printf("%d ",arr[i][j]);
             printf("\n");
        }

}
