#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll LPS(string str)
{
    ll i,j,k,cl,n=str.size();
    ll table[n][n];
    for(i=0;i<n;i++)
        table[i][i]=1;//here we can see the palindromes of length 1
    for(cl=2;cl<=n;cl++)//loop for the subsequences of lengths 2,3,4,...upto len
    {
        for(i=0;i<n-cl+1;i++)
        {
            j=i+cl-1;
            if(str[i]==str[j]&&cl==2)
                table[i][j]=2;
            else if(str[i]==str[j])
                table[i][j]=table[i+1][j-1]+2;
            else
                table[i][j]=max(table[i+1][j],table[i][j-1]);
        }
    }
    return table[0][n-1];
}
int main()
{
    string str;
    ll test,i,j,len_of_lps;
    scanf("%lld",&test);
    while(test--)
    {
        cin>>str;
        len_of_lps=LPS(str);
        printf("length of longest common palindromic subsequence is %lld:\n",len_of_lps);
    }
}

