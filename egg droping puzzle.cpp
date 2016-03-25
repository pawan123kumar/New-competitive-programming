#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll find_ans(int num,int k)//num is number of eggs here
{
    int flag;
    vector< vector<int> > arr(num+1,vector<int>(k+1));
    for(int i=0;i<=num;i++)
    {
        arr[i][0]=0;
        arr[i][1]=1;
    }
    for(int j=1;j<=k;j++)
        arr[1][j]=j;
    for(int i=2;i<=num;i++)//number of eggs
    {
        for(int j=2;j<=k;j++)//number of floors
        {
            arr[i][j]=INT_MAX;
            for(int x=1;x<=j;x++)
            {
                flag=1+max(arr[i-1][x-1],arr[i][j-x]);
                if(flag<arr[i][j])
                    arr[i][j]=flag;
            }
        }
    }
    return arr[num][k];
}
int main()
{
    ll a,b,num,maxx,minn,test,sum,e;
    cin>>e>>num;
    sum=find_ans(e,num);
    cout<<sum;
}


