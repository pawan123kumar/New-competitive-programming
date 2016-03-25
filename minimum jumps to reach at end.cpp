//Given an array of integers where each element represents the max number of steps that can be made forward from that element.
// Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element).
// If an element is 0, then cannot move through that element.
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> arr(1000001);
vector<ll> jumps(1000001);
void find_min_jumps(ll num)
{
    if((num==0)||(arr[0]==0))
    {
        cout<<"not possible to reach to end:"<<endl;
        return;
    }
    jumps[0]=0;
    for(ll i=1;i<num;i++)
    {
        jumps[i]=INT_MAX;
        for(ll j=0;j<i;j++)
        {
            if(((j+arr[j])>=i)&&(jumps[j]!=INT_MAX))
                jumps[i]=min(jumps[i],jumps[j]+1);
        }
    }
    //for(ll i=0;i<num;i++)
      //  cout<<jumps[i]<<" ";
    cout<<"minimum jumps required are as: "<<jumps[num-1]<<endl;
}
int main()
{
    ll test,i,j,a,b,num,jumps;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&num);
        for(i=0;i<num;i++)
            scanf("%lld",&arr[i]);
        find_min_jumps(num);
    }
}


