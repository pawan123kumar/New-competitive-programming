#include<bits/stdc++.h>
using namespace std;
vector<int> arr(10001);
#define ll long long int
vector<ll> arr1(4001),arr2(4001),arr3(4001);
int main()
{
    ll k,test,a,b,num1,num2,num3,i,j;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld%lld%lld",&num1,&num2,&num3);
        for(i=0;i<num1;i++)
            scanf("%lld",&arr1[i]);
        for(i=0;i<num2;i++)
            scanf("%lld",&arr2[i]);
        for(i=0;i<num3;i++)
            scanf("%lld",&arr3[i]);
        for(i=0,j=0,k=0;((i<num1)&&(j<num2)&&(k<num3));)
        {
            if((arr1[i]==arr2[j])&&(arr2[j]==arr3[k]))
            {
                printf("%lld ",arr1[i]);
                i++,j++,k++;
            }
            else if((arr1[i]<arr2[j])&&(arr1[i]<arr3[k]))
                i++;
            else if((arr2[j]<arr1[i])&&(arr2[j]<arr3[k]))
                j++;
            else if((arr3[k]<arr2[j])&&(arr3[k]<arr1[i]))
                k++;
        }
        printf("\n");
    }
}

