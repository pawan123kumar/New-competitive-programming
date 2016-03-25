#include<bits/stdc++.h>
using namespace std;
int edit_distance(string str1,string str2);
int main()
{
    int test,len;
    string str1,str2;
    scanf("%d",&test);
    while(test--)
    {
        cin>>str1;
        cin>>str2;
        len=edit_distance(str1,str2);
        cout<<len;
    }
}
int edit_distance(string str1,string str2)
{
    int len1=str1.size();
    int len2=str2.size();
    int diff;
    int matrix[len1+1][len2+1];
    for(int i=0;i<=len1;i++)
    {
        for(int j=0;j<=len2;j++)
        {
            if(i==0)
                matrix[i][j]=j;
            else if(j==0)
                matrix[i][j]=i;
            else
            {
                if(str1[i-1]==str2[j-1])
                    diff=0;
                else
                    diff=1;
                matrix[i][j]=min(min(matrix[i-1][j]+1,matrix[i][j-1]+1),matrix[i-1][j-1]+diff);
            }
        }
    }
    return matrix[len1][len2];
}
/*this method is same as the above
#include<bits/stdc++.h>
using namespace std;
int table[101][101];
void print_min_change()
{
    string str1,str2;
    cin>>str1>>str2;
    int len1=str1.length(),len2=str2.length();
    for(int i=0;i<=max(len1,len2);i++)
    {
        table[0][i]=i;
        table[i][0]=i;
    }
    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            if(str1[i-1]==str2[j-1])
                table[i][j]=table[i-1][j-1];
            else
                table[i][j]=1+min(min(table[i-1][j],table[i][j-1]),table[i-1][j-1]);
        }
    }
    cout<<table[len1][len2]<<endl;
}
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        print_min_change();
    }
}
*/
