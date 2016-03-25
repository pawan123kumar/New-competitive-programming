//Given a n*n matrix where numbers all numbers are distinct and are distributed from range 1 to n2.
//find the maximum length path (starting from any cell) such that all cells along the path are increasing order,
// with a difference of 1.We can move in 4 directions from a given cell (i, j), i.e.,
//we can move to (i+1, j) or (i, j+1) or (i-1, j) or (i, j-1) with the condition that the adjacent cell value is only 1 greater
//than the current cell value...
/*Input:  mat[][] = {{1, 2, 9}
                   {5, 3, 8}
                   {4, 6, 7}}
Output: 4
The longest path is 6-7-8-9.*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector< vector<ll> > arr(1001,vector<ll>(1001));
vector< vector<ll> > table(1001,vector<ll>(1001,INT_MIN));
bool is_valid(ll a,ll b,ll num,ll i,ll j)
{
    if((a<1)||(b<1)||(i<1)||(j<1)||(a>num)||(b>num)||(i>num)||(j>num))
        return false;
    else
        return ((arr[i][j]-arr[a][b])==1);
}
ll find_total_paths(ll a,ll b,ll num)
{
    if(table[a][b]!=INT_MIN)
        return table[a][b];
    ll var=0;
    if(is_valid(a,b,num,a-1,b))
        return table[a][b]=1+find_total_paths(a-1,b,num);
    if(is_valid(a,b,num,a+1,b))
        return table[a][b]=1+find_total_paths(a+1,b,num);
    if(is_valid(a,b,num,a,b-1))
        return table[a][b]=1+find_total_paths(a,b-1,num);
    if(is_valid(a,b,num,a,b+1))
        return table[a][b]=1+find_total_paths(a,b+1,num);
    return table[a][b]=1;
}
int main()
{
    ll test,i,j,k,minn,maxx,num,count;
    cin>>num;
    maxx=1;
    for(i=1;i<=num;i++)
        for(j=1;j<=num;j++)
            cin>>arr[i][j];
    for(i=1;i<=num;i++)
    {
        for(j=1;j<=num;j++)
        {
            if(table[i][j]==INT_MIN)
                count=find_total_paths(i,j,num);
            maxx=max(table[i][j],maxx);
        }
    }
    cout<<"the maximum path available is of length:"<<maxx;
}

