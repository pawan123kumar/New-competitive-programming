#include<bits/stdc++.h>
using namespace std;
#define ll int
#define gc getchar_unlocked
ll read_ll()
{
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  ll ret = 0;
  while(c>='0' && c<='9')
  {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
vector< vector<ll> > mat(101,vector<ll>(101));
void solve(ll num,ll m)
{
    ll maxx=0;
    for(ll i=1;i<num;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(j==0)
                mat[i][j]=mat[i][j]+max(mat[i-1][j],mat[i-1][j+1]);
            else if(j==(m-1))
                mat[i][j]=mat[i][j]+max(mat[i-1][j],mat[i-1][j-1]);
            else
                mat[i][j]=mat[i][j]+max(max(mat[i-1][j-1],mat[i-1][j]),mat[i-1][j+1]);
            maxx=max(maxx,mat[i][j]);
            //cout<<mat[i][j]<<" ";
        }
        //cout<<endl;
    }
    printf("%d\n",maxx);
}
int main()
{
    ll test,i,j,num,m;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d",&num,&m);
        for(ll i=0;i<num;i++)
        {
            for(ll j=0;j<m;j++)
                scanf("%d",&mat[i][j]);
        }
        solve(num,m);
    }
}

