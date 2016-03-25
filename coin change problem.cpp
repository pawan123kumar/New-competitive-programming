#include<bits/stdc++.h>
using namespace std;
int coin_change(int coin_arr[],int num_coins,int sum)
{
    int x,y;
    int table[sum+1][num_coins];
    for(int i=0;i<num_coins;i++)
        table[0][i]=1;
    for(int i=1;i<sum+1;i++)
    {
        for(int j=0;j<num_coins;j++)
        {
            x=((i-coin_arr[j])>=0)?table[i-coin_arr[j]][j]:0;
            y=(j>=1)?table[i][j-1]:0;
            table[i][j]=x+y;
        }
    }
    return table[sum][num_coins-1];
}
int main()
{
    int num,n,i,sum;
    scanf("%d",&num);
    int arr[num];
    for(int i=0;i<num;i++)
        scanf("%d",&arr[i]);
    scanf("%d",&sum);
    printf("%d is made through %d ways:",sum,coin_change(arr,num,sum));
}
