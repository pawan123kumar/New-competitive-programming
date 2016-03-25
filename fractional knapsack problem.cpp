//this problem has given a weight and within that weight...how much we can maximize our weight....
//so this is a fractional knapsack problem
#include<bits/stdc++.h>
using  namespace std;
struct combine
{
    float cost;
    int weight;
    float density;
};
struct myfunc
{
    bool operator()(struct combine a,struct combine b)
    {
        return (a.density>b.density);
    }
};
int main()
{
    int test,num,weight;
    float sum;
    scanf("%d",&test);
    while(test--)
    {
        sum=0;
        scanf("%d%d",&num,&weight);
        vector<struct combine> arr(num);
        vector<int> weights(num);
        for(int i=0;i<num;i++)
           scanf("%f",&arr[i].cost);
        for(int i=0;i<num;i++)
            scanf("%d",&arr[i].weight);
        //vector<float> sorted_arr(num);
        for(int i=0;i<num;i++)
            arr[i].density=(arr[i].cost)/(arr[i].weight);
        sort(arr.begin(),arr.end(),myfunc());
        for(int i=0;i<num;i++)
        {
            if(arr[i].weight>=weight)
            {
                sum+=(arr[i].cost*weight)/arr[i].weight;
                break;
            }
            else
            {
                weight=weight-arr[i].weight;
                sum+=arr[i].cost;
            }
        }
        printf("%f\n",sum);
    }
}

