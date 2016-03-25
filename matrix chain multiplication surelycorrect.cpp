#include<bits/stdc++.h>
using namespace std;
int num;
int arr[101];
int m[101][101];
void find_min_cost()
{
    int len,loop,i,j,k,minn,L;
    for(i=1;i<num;i++)
        m[i][i]=0;
    for( L=2; L<num ;L++ )//chain length ..means how many matrices are multiplied at a time
    {
        for( i=1; i<=num-L+1 ;i++ )//to fill diagonals of matrices ..so in each diagonal..how many times loop is executed
        {
            j=L+i-1;
            m[i][j]=INT_MAX;
            for(k=i;k<=j-1;k++)
            {
                minn = m[i][k]+m[k+1][j]+arr[i-1]*arr[k]*arr[j];
                if(m[i][j]>minn)
                    m[i][j]=minn;
            }
        }
    }
    for(i=1;i<num;i++)
    {
        for(j=1;j<num;j++)
            printf("%2d ",m[i][j]);
        cout<<endl;
    }
    cout<<"the minimum number of operations required are:"<<m[1][num-1]<<endl;
}
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&num);//num is total number of matrices which are to be multiplied
        for(int i=0;i<num;i++)
            scanf("%d",&arr[i]);
        find_min_cost();
    }
}
