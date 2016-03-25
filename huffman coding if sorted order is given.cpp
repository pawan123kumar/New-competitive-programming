#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct queue_node
{
    char ch;
    ll freq;
    struct queue_node *left,*right;
};
struct queue_node *newNode(char ch,ll freq)
{
    struct queue_node *temp;
    temp=(struct queue_node *)malloc(sizeof(struct queue_node));
    temp->ch=ch;
    temp->freq=freq;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
};
struct node
{
    char ch;
    ll freq;
};
struct myfunc
{
    bool operator()(struct node a,struct node b)
    {
        return (a.freq<b.freq);
    }
};
struct queue_node *find_min(queue<struct queue_node *> &qu1,queue<struct queue_node *> &qu2)
{
    struct queue_node *temp;
    if(qu1.empty())
    {
        temp=qu2.front();
        qu2.pop();
        return temp;
    }
    if(qu2.empty())
    {
        temp=qu1.front();
        qu1.pop();
        return temp;
    }
    struct queue_node *qu1_fr=qu1.front();
    struct queue_node *qu2_fr=qu2.front();
    ll qu1_freq=qu1_fr->freq;
    ll qu2_freq=qu2_fr->freq;
    if(qu1_freq<qu2_freq)
    {
        temp=qu1.front();
        qu1.pop();
        return temp;
    }
    else
    {
        temp=qu2.front();
        qu2.pop();
        return temp;
    }
};
struct queue_node *build_huffman_tree(struct node arr[],ll num)
{
    struct queue_node *left,*right,*temp;
    queue<struct queue_node *> qu1,qu2;
    for(ll i=0;i<num;i++)
    {
        temp=newNode(arr[i].ch,arr[i].freq);
        qu1.push(temp);
    }
    while(!(qu1.empty()&&qu2.size()==1))//while queue1 is not completely empty and queue2 size is becomes 1
    {
        left=find_min(qu1,qu2);
        right=find_min(qu1,qu2);
        temp=newNode('$',(left->freq+(right->freq)));
        temp->left=left;
        temp->right=right;
        qu2.push(temp);
    }
    temp=qu2.front();
    return temp;
};
void print_the_codes(struct queue_node *root,int temp[],int top)
{
    if((root->left==NULL)&&(root->right==NULL))
    {
        for(int i=0;i<top;i++)
            cout<<temp[i];
        cout<<endl;
        return;
    }
    if(root->left)
    {
        temp[top]=0;
        print_the_codes(root->left,temp,top+1);
    }
    if(root->right)
    {
        temp[top]=1;
        print_the_codes(root->right,temp,top+1);
    }
}
int main()
{
    ll a,b,i,j,p,c,num;
    cin>>num;
    int temp[120];
    int top=0;
    struct node arr[num];
    string str;
    cin>>str;
    for(i=0;str[i];i++)
        arr[i].ch=str[i];
    for(i=0;i<num;i++)
        cin>>arr[i].freq;
    sort(arr,arr+num,myfunc());
    struct queue_node *root=build_huffman_tree(arr,num);
    print_the_codes(root,temp,top);
}

