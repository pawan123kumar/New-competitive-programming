#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > arr(1001,vector<int>(1001));
vector< vector<int> > path(1001,vector<int>(1001));
bool is_safe(int i,int j,int num)
{
    if((i>=0)&&(j>=0)&&(i<num)&&(j<num)&&(arr[i][j]==1))
        return true;
    return false;
}
void print_path(int num)
{
    for (int i = 0; i < num ; i++)
    {
        for (int j = 0; j < num; j++)
            printf(" %d ", path[i][j]);
        printf("\n");
    }
}
bool find_maze(int i,int j,int num)
{
    if((i==num-1)&&(j==num-1))
        return true;
    if(is_safe(i,j,num))
    {
        path[i][j]=1;
        if(find_maze(i,j+1,num))
            return true;
        if(find_maze(i+1,j,num))
            return true;
        path[i][j]=0;
        return false;
    }
    return false;
}
int main()
{
    int test,a,b,i,j,num;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&num);
        for(i=0;i<num;i++)
        {
            for(j=0;j<num;j++)
            {
                scanf("%d",&arr[i][j]);
                path[i][j]=0;
            }
        }
        path[0][0]=1;
        bool res=find_maze(0,0,num);
        if(res)
            printf("YES\n");
        else
            printf("NO\n");

    }
}

