//Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence
//1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, …
//shows the first 11 ugly numbers. By convention, 1 is included.
//Write a program to find and print the 150’th ugly number
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define sc1(x) scanf("%lld",&x)
#define sc2(x,y) scanf("%lld%lld",&x,&y)
vector<ll> arr(10001);
void ugly_numbers()
{
    ll next_multi_2=0,next_multi_3=0,next_multi_5=0;
    ll i,j,num=0,next_min;
    arr[0]=1;
    for(ll i=1;i<10000;i++)
    {
        next_min=min(2*arr[next_multi_2],min(3*arr[next_multi_3],5*arr[next_multi_5]));
        arr[i]=next_min;
        if(next_min==(2*arr[next_multi_2]))
        {   next_multi_2++;   }
        if(next_min==(3*arr[next_multi_3]))
        {   next_multi_3++;   }
        if(next_min==(5*arr[next_multi_5]))
        {   next_multi_5++;   }
    }
}
int main()
{
    ll test,i,j,a,b,minn,n,maxx;
    ugly_numbers();
    sc1(test);
    while(test--)
    {
        sc1(n);//find the nth ugly number
        printf("%lld\n",arr[n-1]);
    }
}

