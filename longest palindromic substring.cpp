#include<bits/stdc++.h>
using namespace std;
#define ll long  long int
vector< vector<bool> > table(1001,vector<bool>(1001));
void print_longest_palindromic(string str)
{
    ll i,j,k,total,len=str.length();
    for(i=0;i<len;i++)
        table[i][i]=true;
    ll index=0,longest=0;
    for(i=0;i<(len-1);i++)
    {
        if(str[i]==str[i+1])
        {
            index=i;
            longest=2;
            table[i][i+1]=true;
        }
        else
            table[i][i+1]=false;
    }
    for(k=2;k<=(len-1);k++)
    {
        for(i=0;i<=(len-k);i++)
        {
            j=i+k;
            if(str[i]==str[j]&&(table[i+1][j-1]==true))
            {
                table[i][j]=true;
                if(k>longest)
                {
                    longest=k+1;
                    index=i;
                }
            }
            else
                table[i][j]=false;
        }
    }
    if(longest==0)//if there is no palindrome exist for length greater than 2
    {
        longest=1;
        index=0;
    }
    cout<<"length is : "<<longest<<endl;
    ll end_index=index+longest;
    cout<<"longest palindromic substring is : ";
    for(ll i=index;i<=(end_index-1);i++)
        cout<<str[i];
    cout<<endl;
}
int main()
{
    ll test,i,j,k,a,b;
    scanf("%lld",&test);
    string str;
    while(test--)
    {
        cin>>str;
        print_longest_palindromic(str);
    }
}
