#include<bits/stdc++.h>
using namespace std;
struct interval
{
    int start,finall;
};
struct myfunc
{
    bool operator()(struct interval a,struct interval b)
    {
        if(a.finall==b.finall)
           return (a.start<b.start);
        else
            return (a.finall<b.finall);
    }
};
int main()
{
  int test,num;
  scanf("%d",&test);
  while(test--)
  {
      scanf("%d",&num);
      struct interval arr[num];
      for(int i=0;i<num;i++)
          scanf("%d%d",&arr[i].start,&arr[i].finall);
      sort(arr,arr+num,myfunc());
      int sum=1;
      int last_interval=arr[0].finall;
      cout<<arr[0].start<<" "<<arr[0].finall<<endl;
      for(int i=1;i<num;i++)
      {
          if(last_interval<arr[i].start)
          {
              printf("%d %d\n",arr[i].start,arr[i].finall);
              last_interval=arr[i].finall;
              sum+=1;
          }
      }
      printf("\n%d\n",sum);
  }
}

