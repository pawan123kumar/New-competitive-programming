//this is the reversal algorithm ...this depends upon reverse array to d elements and then reverse after d elements..and then
//reverse whole array..example...1 2 3 4 5...d=2..then first reversal ..2 1 3 4 5..after d...2 1 5 4 3..
//and then whole of the array...3 4 5 1 2..this is our final array..
#include<bits/stdc++.h>
using namespace std;
void rotate_arr(int num,int d);
void reverse_arr(int start,int end);
int arr[100];
int main()
{
    int num,d;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
        scanf("%d",&arr[i]);
    scanf("%d",&d);
    rotate_arr(num,d);
    for(int i=0;i<num;i++)
        printf("%d ",arr[i]);
}
void rotate_arr(int num,int d)
{
    //vector<int>::iterator itr;
    //itr=arr.begin();
    reverse_arr(0,d-1);
    reverse_arr(d,num-1);
    reverse_arr(0,num-1);
    //reverse(arr.begin(),arr.begin()+num);
}
void reverse_arr(int start,int end)
{
    int temp,i,j;
    for(i=start,j=end;i<=j;i++,j--)
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}

