#include<bits/stdc++.h>
#define ll int//change it to long long int if required
using namespace std;
vector< vector<ll> > board(101,vector<ll>(101));
bool safe_queen(int row,int col,int num)//checking for this queen can be placed at safe position or not
{//return true..means queen is placed safely at (row,col)...false means queen is not safe,means queen is attacked
    for(int i=0;i<col;i++)//check for attacked by entire row
        if(board[row][i])
            return false;
    for(int i=row,j=col;i>=0&&j>=0;i--,j--)//check for attacked by upper diagonal part
        if(board[i][j])
            return false;
    for(int i=row,j=col;i<num&&j>=0;i++,j--)//check for attacked by lower diagonal part
        if(board[i][j])
            return false;
    return true;
}
bool solve_queen(int num,int col)
{
    if(col>=num)//it means all queens are placed at their correct positions
        return true;
    for(int i=0;i<num;i++)
    {
        if(safe_queen(i,col,num))
        {
            board[i][col]=1;
            if(solve_queen(num,col+1))
                return true;
            board[i][col]=0;//this is the backtracking part
        }
    }
    return false;//If queen can not be place in any row in this column col,then return false
}
int main()
{
    ll test,a,b,num,i,j;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&num);//it means in N*N board, we have to place queens
        for(i=0;i<num;i++)
            for(j=0;j<num;j++)
                board[i][j]=0;
        if( solve_queen(num,0) && (num>3) )//here 0 is col,means columns which are placed already...here only (num>3)
        {
            for(i=0;i<num;i++)
            {
                for(j=0;j<num;j++)
                    printf("%d ",board[i][j]);
                printf("\n");
            }
        }
        else
            printf("queen can't be placed on %d*%d board:\n");
    }
}
