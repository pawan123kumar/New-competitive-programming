#include<bits/stdc++.h>
using namespace std;
int coin_change(int coin_arr[],int num_coins,int sum)
{
    int x,y,minn;
    int cp[sum+1];
    cp[0]=0;
    for(int p=1;p<=sum;p++)
    {
        minn=9999;
        if((p-coin_arr[0])>=0)
        {
            for(int i=0;i<num_coins;i++)
            {
                if((p-coin_arr[i])>=0)
                {
                    if(cp[p-coin_arr[i]]<minn)
                        minn=cp[p-coin_arr[i]]+1;
                }
                else
                    break;
            }
        }
        cp[p]=minn;
    }
    for(int i=0;i<=sum;i++)
        printf("%d ",cp[i]);
    return cp[sum];
}
int main()
{
    int num,n,i,sum;
    scanf("%d",&num);
    int arr[num];
    for(int i=0;i<num;i++)
        scanf("%d",&arr[i]);
    scanf("%d",&sum);
    printf("\n%d is made up of minimum %d coins:",sum,coin_change(arr,num,sum));
}

