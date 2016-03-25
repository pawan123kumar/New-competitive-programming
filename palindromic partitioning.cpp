//minimum cuts means here is to find the cuts which made every substring is a plaindrome
// for example-- in abbac..2 cuts are needed for palindromic partitioning..abba and c both are palindromes
//in aba--no cuts needed..bcz string is already a palindrome
//in abacc..2 cuts are needed...aba and cc
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll min_cuts_for_pd(string str)
{
    ll L,len=str.length(),i,j,k,total;
    ll c[len];
    bool p[len][len];
    for(i=0;i<len;i++)
    {
        p[i][i]=true;
    }
    for(L=2;L<=len;L++)
    {
        for(i=0;i<len-L+1;i++)
        {
            j=i+L-1;
            if(L==2)
                p[i][j]=(str[i]==str[j]);
            else
                p[i][j]=(str[i]==str[j])&&p[i+1][j-1];
        }
    }
    for(i=0;i<len;i++)
    {
        if(p[0][i]==true)
            c[i]=0;
        else
        {
            c[i]=INT_MAX;
            for(j=0;j<i;j++)
            {
                if(p[j+1][i]==true&&1+c[j]<c[i])
                    c[i]=c[j]+1;
            }
        }
    }
    return c[len-1];
}
int main()
{
    ll i,j,num,test;
    scanf("%lld",&test);
    while(test--)
    {
        string str;
        cin>>str;
        num=min_cuts_for_pd(str);
        printf("the minimum cuts needed for palindromic partitioning are as:%lld\n",num);
    }
}

