#include<cstdio>
#include<iostream>
#include<string>
int maxx(int a,int b)
{
    return a>b?a:b;
}
using namespace std;
void LCS(string str1,string str2);
int main()
{
    int test;
    string str1,str2;
    scanf("%d",&test);
    while(test--)
    {
        cin>>str1;
        cin>>str2;
        LCS(str1,str2);
    }
}
void LCS(string str1,string str2)
{
    int len1=str1.size(),len2=str2.size();
    int arr[len1][len2];
    for(int i=0;i<len1;i++)
    {
        for(int j=0;j<len2;j++)
        {
            if(i==0||j==0)
                arr[i][j]=0;
            else if(str1[i-1]==str2[j-1])
                arr[i][j]=1+arr[i-1][j-1];
            else
                arr[i][j]=maxx(arr[i][j-1],arr[i-1][j]);
        }
    }
    cout<<"the longest common subsequence in string:"<<str1<<"and string:"<<str2<<"is :"<<(arr[len1-1][len2-1]+1)<<endl;
}

