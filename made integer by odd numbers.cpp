//here given an integer and we have to made it by use of 1 or more odd numbers..
//for ex. if N=3..then it can be made in two ways..(1+2),(1+1+1)..
//if N=2,then it can be made in only one way...(1+1)..
#include<bits/stdc++.h>
#define ll long long int
#define modulo (1000000000+7)
void multiply(ll f[2][2],ll M[2][2])
{
    ll a,b,c,d;
    a=(((f[0][0]%modulo)*(M[0][0]%modulo))%modulo+((f[0][1]%modulo)*(M[1][0]%modulo))%modulo)%modulo;
    b=(((f[0][0]%modulo)*(M[0][1]%modulo))%modulo+((f[0][1]%modulo)*(M[1][1]%modulo))%modulo)%modulo;
    c=(((f[1][0]%modulo)*(M[0][0]%modulo))%modulo+((f[1][1]%modulo)*(M[1][0]%modulo))%modulo)%modulo;
    d=(((f[1][0]%modulo)*(M[0][1]%modulo))%modulo+((f[1][1]%modulo)*(M[1][1]%modulo))%modulo)%modulo;
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
        cout<<fib<<endl;
    }
}




