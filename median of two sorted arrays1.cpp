#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll getMedianRec(ll ar1[], ll ar2[], ll left, ll right, ll n);

/* This function returns median of ar1[] and ar2[].
   Assumptions in this function:
   Both ar1[] and ar2[] are sorted arrays
   Both have n elements */
ll getMedian(ll ar1[], ll ar2[], ll n)
{
    if(ar1[n-1]<ar2[0])
        return (ar1[n-1]+ar2[0])/2;
    else if(ar2[n-1]<ar1[0])
        return (ar2[n-1]+ar1[0])/2;
    return getMedianRec(ar1, ar2, 0, n-1, n);
}

/* A recursive function to get the median of ar1[] and ar2[]
   using binary search */
ll getMedianRec(ll ar1[], ll ar2[], ll left, ll right, ll n)
{
    ll i, j;

    /* We have reached at the end (left or right) of ar1[] */
    if (left > right)
        return getMedianRec(ar2, ar1, 0, n-1, n);

    i = (left + right)/2;
    j = n - i - 1;  /* Index of ar2[] */

    /* Recursion terminates here.*/
    if (ar1[i] > ar2[j] && (j == n-1 || ar1[i] <= ar2[j+1]))
    {
        /* ar1[i] is decided as median 2, now select the median 1
           (element just before ar1[i] in merged array) to get the
           average of both*/
        if (i == 0 || ar2[j] > ar1[i-1])
            return (ar1[i] + ar2[j])/2;
        else
            return (ar1[i] + ar1[i-1])/2;
    }

    /*Search in left half of ar1[]*/
    else if (ar1[i] > ar2[j] && j != n-1 && ar1[i] > ar2[j+1])
        return getMedianRec(ar1, ar2, left, i-1, n);

    /*Search in right half of ar1[]*/
    else /* ar1[i] is smaller than both ar2[j] and ar2[j+1]*/
        return getMedianRec(ar1, ar2, i+1, right, n);
}

/* Driver program to test above function */
int main()
{
    ll ans,test,num,i,j,key;
    scanf("%lld",&test);
    ll arr1[10001],arr2[10001];
    while(test--)
    {
        scanf("%lld",&num);
        for(i=0;i<num;i++)
            scanf("%lld",&arr1[i]);
        for(i=0;i<num;i++)
            scanf("%lld",&arr2[i]);
        ans=getMedian(arr1, arr2, num);
        printf("%lld is the median of given array:\n",ans);
    }
}

