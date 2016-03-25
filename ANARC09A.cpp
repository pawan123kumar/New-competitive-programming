#include<bits/stdc++.h>
using namespace std;
#define ll int
char str[2001];
int main()
{
    ll len,test,i,j,num,ans,k=0,cnt;
    char ch_l='{';
    char ch_r='}';
    while(true)
    {
        cnt=0;
        scanf("%s",str);
        //printf("%s",str);
        if(str[0]=='-')
            break;
        stack<char> st1;
        k+=1;
        i=0;
        len=strlen(str);
        while(i<len)
        {
            if(str[i]=='}')
            {
                if(st1.size()>0)
                    st1.pop();
                else
                    cnt++;
            }
            else
                st1.push('{');
            i++;
        }
        ans=cnt/2+st1.size()/2;
        if((cnt&1)&&(st1.size()&1))
            ans+=2;
        printf("%d. %d\n",k,ans);
    }
}

