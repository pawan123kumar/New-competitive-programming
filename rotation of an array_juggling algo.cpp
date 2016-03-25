#include<bits/stdc++.h>//this algorithm based on the gcd of n(total no. of elements) and d(rotation elements)..gcd(n,d)..
//therefore it moves the elements within the sets of gcd of array....
using namespace std;
/* function to print an array */
void printArray(int arr[], int size);

/*Fuction to get gcd of a and b*/
int gcd(int a,int b);

/*Function to left rotate arr[] of siz n by d*/
void leftRotate(int arr[], int d, int n)
{
  int i, j, k, temp;
  for (i = 0; i < gcd(d, n); i++)
  {
    /* move i-th values of blocks */
    temp = arr[i];
    j = i;
    while(1)
    {
      k = j + d;
      if (k >= n)
        k = k - n;
      if (k == i)
        break;
      arr[j] = arr[k];
      j = k;
    }
    arr[j] = temp;
  }
}

/*UTILITY FUNCTIONS*/
/* function to print an array */
void printArray(int arr[], int size)
{
  int i;
  for(i = 0; i < size; i++)
    printf("%d ", arr[i]);
}

/*Fuction to get gcd of a and b*/
int gcd(int a,int b)
{
   if(b==0)
     return a;
   else
     return gcd(b, a%b);
}

/* Driver program to test above functions */
int main()
{
    int num;
    scanf("%d",&num);
    int d,arr[num];
    for(int i=0;i<num;i++)
        scanf("%d",&arr[i]);
   scanf("%d",&d);
   leftRotate(arr, d, num);
   printArray(arr, num);
   getchar();
   return 0;
}

