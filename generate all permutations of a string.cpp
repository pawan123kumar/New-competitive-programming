#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll total;
void print_all_permutations(string str,ll index,ll len)
{
    if(index==len)
    {
        total++;
        cout<<total<<" "<<str<<endl;
    }
    else
    {
        for(ll i=index;i<len;i++)
        {
            swap(str[i],str[index]);
            print_all_permutations(str,index+1,len);
            swap(str[i],str[index]);//backtracking step
        }
    }
}
int main()
{
    ll test,num;
    scanf("%lld",&test);
    string str;
    while(test--)
    {
        total=0;
        cin>>str;
        printf("all permutations are as:\n");
        print_all_permutations(str,0,str.length());
    }
}

