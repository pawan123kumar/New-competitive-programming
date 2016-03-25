#include<bits/stdc++.h>
using namespace std;
struct train
{
    int time;
    int status;
};
struct myfunc
{
    bool operator()(struct train a,struct train b)
    {
        return (a.time<b.time);
    }
};
int main()
{
    int test,num;
    scanf("%d",&test);
    while(test--)
    {
        printf("\nenter the total number of trains:");
        scanf("%d",&num);
        printf("enter train timings:as 0900 means 9am\n");
        vector<struct train> arr(2*num);
        for(int i=0;i<2*num;i++)
        {
            scanf("%d",&arr[i].time);
            if(i%2==0)
                arr[i].status=1;
            else
                arr[i].status=-1;
        }
        sort(arr.begin(),arr.end(),myfunc());
        vector<int> final_arr;//to store all of the timings of the trains...means size=2*num
        for(int i=0;i<2*num;i++)
        {
            final_arr.push_back(arr[i].status);
        }
        int maxx=final_arr[0];
        for(int i=1;i<2*num;i++)
        {
            final_arr[i]=final_arr[i]+final_arr[i-1];
            if(maxx<final_arr[i])
                maxx=final_arr[i];
        }
        printf("the minimum number of trains required are %d",maxx);
    }
}

