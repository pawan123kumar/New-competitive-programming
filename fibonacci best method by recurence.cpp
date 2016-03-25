//complexity of this method is O(logn) and space complexity is O(1)
#include<bits/stdc++.h>
#define ll long long int
void multiply(ll f[2][2],ll M[2][2])
{
    ll a,b,c,d;
    a=f[0][0]*M[0][0]+f[0][1]*M[1][0];
    b=f[0][0]*M[0][1]+f[0][1]*M[1][1];
    c=f[1][0]*M[0][0]+f[1][1]*M[1][0];
    d=f[1][0]*M[0][1]+f[1][1]*M[1][1];
    f[0][0]=a;
    f[0][1]=b;
    f[1][0]=c;
    f[1][1]=d;
}
void power(ll f[2][2],ll num)
{
    if(num==0||num==1)
        return;
    ll M[2][2]={1,1,1,0};
    power(f,num/2);
    multiply(f,f);
    if((num%2)!=0)
        multiply(f,M);
}
ll fibonacci(ll num)
{
    ll f[2][2]={1,1,1,0};
    if(num==0)
        return 0;
    power(f,num-1);
    return f[0][0];
}
using namespace std;
int main()
{
    ll fib,i,n,num,test;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&num);
        fib=fibonacci(num);
        printf("%lld is %lldth fibonacci number:\n",fib,num);
    }
}


