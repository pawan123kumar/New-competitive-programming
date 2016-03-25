#include<bits/stdc++.h>
using namespace std;
int arr[101][101];
int num;
int find_num_paths();
int main()
{
    scanf("%d",&num);
    for(int i=0;i<num;i++)//enter the path matrix with blocked paths=-1 and unblocked paths with 0..
    {
        for(int j=0;j<num;j++)
            scanf("%d",&arr[i][j]);
    }
    int sum=find_num_paths();
    if(sum<0)
        printf("destination is not reachable:");
    else
        printf("destination is reachable and number of ways are: %d",sum);
}
int find_num_paths()
{
    int flag_row=0;
    int flag_col=0;
    if(arr[0][1]==-1&&arr[1][0]==-1)
    {
        printf("graph is not traversable:");
        return -1;
    }
    for(int i=1;i<num;i++)//to set the topmost row and the left most column....
    {
        if(flag_row==1);
        else
        {
            if(arr[0][i]==-1)
                flag_row=1;
            else
                arr[0][i]=1;
        }
        if(flag_col==1);
        else
        {
            if(arr[i][0]==-1)
                flag_col=1;
            else
                arr[i][0]=1;
        }
    }
    for(int i=1;i<num;i++)
    {
        for(int j=1;j<num;j++)
        {
            if(arr[i][j]==-1)//ignore the paths which are blocked
                continue;
            if(arr[i-1][j]>0)
                arr[i][j]+=arr[i-1][j];
            if(arr[i][j-1]>0)
                arr[i][j]+=arr[i][j-1];
        }
    }
    return arr[num-1][num-1];
}

