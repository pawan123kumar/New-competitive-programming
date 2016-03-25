/*this uses the concept of LCS problem*/
#include<bits/stdc++.h>
using namespace std;
char str[5001];
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
void find_lcs(int len)
{
    vector< vector<int> > mat(len+1,vector<int>(len+1,0));
    int ans;
    for(int i=len-1;i>=0;i--)
    {
        for(int j=i+1;j<len;j++)
        {
            int &loc=mat[i][j];
            if(str[i]==str[j])
                loc=mat[i+1][j-1];
            else
                loc=1+min(mat[i+1][j],mat[i][j-1]);
        }
    }
    //ans=len-mat[len%2][len];
    printf("%d",mat[0][len-1]);
}
int main()
{
    char temp;
    int len;
    len=read_ll();
    scanf("%s",str);
    find_lcs(len);
}

