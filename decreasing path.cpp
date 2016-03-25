//here we have given a matrix.we are allowed to go to 4 directions available,but not outside the boundary of the matrix
//we go in left,right,top,bottom if and only if..the value stored at that position is greater than all others directions..
// we have to calculate the total paths
//for example,we have given num=2 and matrix is 1 2 1 3..then answer is 8..
//8=(1,1)+(2,2)+(3,3)+(4,4)+(2,1)+(3,2)+(3,2,1)..so total paths available are 8....:)
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
vector< vector<ll> > arr(1001,vector<ll>(1001));
vector< vector<ll> > table(1001,vector<ll>(1001,INT_MIN));
bool is_valid(ll a,ll b,ll num,ll i,ll j)
{
    if((a<1)||(b<1)||(a>num)||(b>num)||(i<1)||(j<1)||(i>num)||(j>num))
        return false;
    else if((arr[a][b]<=arr[i][j]))
        return false;
    else
        return true;
}
ll find_total_paths(ll a,ll b,ll num)
{
    if(table[a][b]!=INT_MIN)
        return table[a][b];
    ll var=0;
    table[a][b]=0;
    if(is_valid(a,b,num,a-1,b))
        var=(var+1+find_total_paths(a-1,b,num))%mod;
    if(is_valid(a,b,num,a+1,b))
        var=(var+1+find_total_paths(a+1,b,num))%mod;
    if(is_valid(a,b,num,a,b-1))
        var=(var+1+find_total_paths(a,b-1,num))%mod;
    if(is_valid(a,b,num,a,b+1))
        var=(var+1+find_total_paths(a,b+1,num))%mod;
    table[a][b]=(table[a][b]+var)%mod;
    return table[a][b];
}
int main()
{
    ll total,num,i,j;
    cin>>num;
    for(i=1;i<=num;i++)
    {
        for(j=1;j<=num;j++)
            cin>>arr[i][j];
    }
    total=(num*num)%mod;
    for(i=1;i<=num;i++)
    {
        for(j=1;j<=num;j++)
        {
            if(table[i][j]!=INT_MIN)
                total=(total+table[i][j])%mod;
            else
                total=(total+find_total_paths(i,j,num))%mod;
        }
    }
    cout<<total;
}


