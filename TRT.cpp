/*here we use recursion,bcz we are not sure about choosing the next element*/
/*in parallel we use DP to store the intermediate repeated results */
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define set_bits(x) __builtin_popcount(x)
#define sc1ll(x) scanf("%lld",&x)
vector<ll> arr(2001);
ll num;
vector<vector<ll> > mat(2001,vector<ll>(2001,0));
ll solve(ll day_no,ll start_index,ll end_index)
{
    if((start_index>end_index)||(start_index>=num))
        return 0;
    if(start_index==end_index)//if there is only one element,then directly multiply that day with treat's value
    {
        mat[start_index][end_index]=day_no*arr[start_index];
        return mat[start_index][end_index];
    }
    if(mat[start_index][end_index]==0)//here either choose last one or choose first one and iterate according to that
        mat[start_index][end_index]=max(arr[start_index]*day_no+solve(day_no+1,start_index+1,end_index),arr[end_index]*day_no+solve(day_no+1,start_index,end_index-1));
    return mat[start_index][end_index];
}
int main()
{
    ll test,i,j,maxx,minn,ans;
    sc1ll(num);
    if(num==1)
    {
        sc1ll(maxx);
        printf("%lld",maxx);
        return 0;
    }
    for(i=0;i<num;i++)
        sc1ll(arr[i]);
    ans=solve(1,0,num-1);
    printf("%lld",ans);
}


