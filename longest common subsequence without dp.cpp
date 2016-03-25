#include<cstdio>
#include<iostream>
using namespace std;
int LCS(string str1,string str2,int len1,int len2);
int maxx(int a,int b)
{
    return (a>b)?a:b;
}
int main()
{
    int test,lcs,len1,len2;
    scanf("%d",&test);
    string str1,str2;
    while(test--)
    {
        cin>>str1;
        cin>>str2;
        len1=str1.size();
        len2=str2.size();
        lcs=LCS(str1,str2,len1,len2);
        printf("the longest common subsequence is of length:%d\n",lcs);
    }
}
int LCS(string str1,string str2,int len1,int len2)
{
    if(len1==0||len2==0)
        return 0;
    if(str1[len1]==str2[len2])
        return 1+LCS(str1,str2,len1-1,len2-1);
    else
        return maxx(LCS(str1,str2,len1-1,len2),LCS(str1,str2,len1,len2-1));
}

