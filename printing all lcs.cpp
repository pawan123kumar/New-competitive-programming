#include<bits/stdc++.h>
int maxx(int a,int b)
{
    return a>b?a:b;
}
using namespace std;
vector< vector<int> > arr(101,vector<int>(101));
void LCS(string str1,string str2);
void print_all_lcs(string str1,string str2,int i,int j,int index,char prarr[]);
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
    for(int i=0;i<=len1;i++)
    {
        for(int j=0;j<=len2;j++)
        {
            if(i==0||j==0)
                arr[i][j]=0;
            else if(str1[i-1]==str2[j-1])
                arr[i][j]=1+arr[i-1][j-1];
            else
                arr[i][j]=maxx(arr[i][j-1],arr[i-1][j]);
        }
    }
    cout<<arr[len1][len2]<<endl;
    char prarr[50];
    print_all_lcs(str1,str2,len1,len2,0,prarr);
    //cout<<"the longest common subsequence in string:"<<str1<<"and string:"<<str2<<"is :"<<(arr[len1-1][len2-1]+1)<<endl;
}
void print_all_lcs(string str1,string str2,int i,int j,int index,char prarr[])
{
    //if(i==0||j==0)
    if(arr[i][j]==0)
    {
        for(int l=index-1;l>=0;l--)
            cout<<prarr[l];
        cout<<endl;
        return;
    }
    if(str1[i-1]==str2[j-1])
    {
        prarr[index++]=str2[j-1];
        print_all_lcs(str1,str2,i-1,j-1,index,prarr);
    }
    else
    {
        if(arr[i-1][j]==arr[i][j-1])
        {
            //prarr[index++]=str1[i-1];
            print_all_lcs(str1,str2,i-1,j,index,prarr);
            print_all_lcs(str1,str2,i,j-1,index,prarr);
        }
        else if(arr[i-1][j]>arr[i][j-1])
            print_all_lcs(str1,str2,i-1,j,index,prarr);
        else
            print_all_lcs(str1,str2,i,j-1,index,prarr);
    }
}



