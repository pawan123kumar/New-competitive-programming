#include<bits/stdc++.h>
using namespace std;
struct jobs
{
    int dead;
    int profit;
};
struct myfunc
{
    bool operator()(struct jobs a,struct jobs b)
    {
        return (a.profit>=b.profit);
    }
};
struct jobs arr[10000];
int main()
{
    int test,num,i,j,k,dead,profit,current_dead;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&num);
        int maxx=0;
        for(i=0;i<num;i++)
        {
            scanf("%d%d",&dead,&profit);
            arr[i].dead=dead;
            arr[i].profit=profit;
            if(dead>maxx)
                maxx=dead;
        }
        sort(arr,arr+num,myfunc());
        vector<int> deadlines(maxx+1,0);
        deadlines[arr[0].dead]=1;
        int sum=arr[0].profit;
        for(int i=1;i<num;i++)
        {
            //current_dead=arr[i].dead;
            if(deadlines[arr[i].dead]==0)
            {
                sum+=arr[i].profit;
                deadlines[arr[i].dead]=1;
            }
            else
            {
                for(j=arr[i].dead;j>=1;j--)
                {
                    if(deadlines[j]==0)
                    {
                        deadlines[j]=1;
                        sum+=arr[i].profit;
                        break;
                    }
                }
            }
        }
        printf("%d is the maximum profit:\n",sum);
    }
}

