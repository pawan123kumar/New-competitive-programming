//this code is for the sorted array which is rotated.......means the array is 5 6 7 8 1 2 3 4
//and we want to find out the element in the given array....so we use it
#include <bits/stdc++.h>
using namespace std;
int findPivot(int[], int, int);
int binarySearch(int[], int, int, int);
int pivotedBinarySearch(int arr[], int arr_size, int no)
{
   int pivot = findPivot(arr, 0, arr_size-1);

   // If we didn't find a pivot, then array is not rotated at all
   if (pivot == -1)
     return binarySearch(arr, 0, arr_size-1, no);

   // If we found a pivot, then first compare with pivot and then
   // search in two subarrays around pivot
   if (arr[pivot] == no)
     return pivot;
   if (arr[0] <= no)
     return binarySearch(arr, 0, pivot-1, no);
   else
     return binarySearch(arr, pivot+1, arr_size-1, no);
}

/* Function to get pivot. For array 3, 4, 5, 6, 1, 2 it will
   return 3. If array is not rotated at all, then it returns -1 */
int findPivot(int arr[], int low, int high)
{
   // base cases
   if (high < low)  return -1;
   if (high == low) return low;

   int mid = (low + high)/2;   /*low + (high - low)/2;*/
   if (mid < high && arr[mid] > arr[mid + 1])
     return mid;
   if (mid > low && arr[mid] < arr[mid - 1])
     return (mid-1);
   if (arr[low] >= arr[mid])
     return findPivot(arr, low, mid-1);
   else
     return findPivot(arr, mid + 1, high);
}

/* Standard Binary Search function*/
int binarySearch(int arr[], int low, int high, int no)
{
   if (high < low)
       return -1;
   int mid = (low + high)/2;  /*low + (high - low)/2;*/
   if (no == arr[mid])
     return mid;
   if (no > arr[mid])
     return binarySearch(arr, (mid + 1), high, no);
   else
     return binarySearch(arr, low, (mid -1), no);
}
int main()
{
    int n,num;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("enter the number u want to search::");
    scanf("%d",&num);
    int index=pivotedBinarySearch(arr,n,num);
    if(index==-1)
        printf("the element is not in the list:");
    else
        printf("element is in the list at position %d:",index);
}

