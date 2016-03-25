#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector< vector<bool> > table(1001,vector<bool>(1001));
vector<ll> min_cuts(1001);
vector<ll> cuts_path(1001);
void min_cuts_and_find_cuts(string str)
{
    ll len,i,j,total,minn;
    for(i=0;i<str.length();i++)
    {
        cuts_path[i]=-1;
        table[i][i]=true;
    }
    for(len=1;len<str.length();len++)
    {
        j=len;
        for(i=0;(i+j)<str.length();i++)
        {
            table[i][i+j]=false;
            if(str[i]==str[i+j])
            {
                if(len==1)
                    table[i][i+j]=true;
                else if(table[i+1][i+j-1]==true)
                    table[i][i+j]=true;
            }
        }
    }
    min_cuts[0]=0;
    for(i=1;i<str.length();i++)
    {
        if(table[0][i])//if palindrome is a prefix then its begin 0 cuts
        {
            min_cuts[i]=0;
            //cuts_path[i]=i;
        }
        else
        {
            min_cuts[i]=INT_MAX;
            for(j=0;j<i;j++)
            {
                if(table[j+1][i]&&(1+min_cuts[j])<min_cuts[i])
                {
                    min_cuts[i]=min_cuts[j]+1;
                    //cuts_path[i]=j;
                }
            }
        }
    }
    cout<<"minimum cuts needed are: "<<min_cuts[str.length()-1]<<endl;
    //for(i=0;i<str.length();i++)
      //  cout<<min_cuts[i]<<" "<<cuts_path[i]<<endl;
}
#define sc1(x) scanf("%lld",&x)
int main()
{
    ll a,b,test,i,j,num;
    string str;
    sc1(test);
    while(test--)
    {
        cin>>str;
        min_cuts_and_find_cuts(str);
    }

}


