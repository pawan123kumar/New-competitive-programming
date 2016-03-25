//application of lowest common ancestor is to find the distance betweeen the two nodes..:)
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct node
{
    ll data;
    struct node *left,*right;
};
struct node *create_node(ll data)
{
    struct node *start;
    start=(struct node *)malloc(sizeof(struct node));
    start->data=data;
    start->left=NULL;
    start->right=NULL;
    return start;
}
struct node *minValueNode(struct node* node)
{
    struct node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}
struct node *delete_from_bst(struct node* root,ll data)
{
    if (root == NULL) return root;
    if (data < root->data)
        root->left = delete_from_bst(root->left, data);
    else if (data > root->data)
        root->right = delete_from_bst(root->right, data);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = delete_from_bst(root->right, temp->data);
    }
    return root;
}
struct node *insert_in_bst(struct node *root,ll data)
{
    struct node *start;
    start=root;
    if(root==NULL)
        return create_node(data);
    else if(data==root->data)
        return root;
    else if(data>root->data)
        root->right=insert_in_bst(root->right,data);
    else
        root->left=insert_in_bst(root->left,data);
    return root;
}
bool search_in_bst(struct node *root,ll data)
{
    if(root)
    {
        if(root->data==data)
            return true;
        else if((root->data)<data)
            return search_in_bst(root->right,data);
        else
            return search_in_bst(root->left,data);
    }
    return false;
}
void inorder_traversal(struct node *start)
{
    if(start)
    {
        inorder_traversal(start->left);
        cout<<(start->data)<<" ";
        inorder_traversal(start->right);
    }
}
struct node *find_lowest_common_ancestor(struct node *root,ll first,ll second)
{
    if(root==NULL)
        return NULL;
    else
    {
        ll data=root->data;
        if(first<data&&second<data)
            return find_lowest_common_ancestor(root->left,first,second);
        else if(first>data&&second>data)
            return find_lowest_common_ancestor(root->right,first,second);
        else
            return root;
    }
}
void delete_tree(struct node *root)
{
    if(root==NULL)
        return;
    else
    {
        delete_tree(root->left);
        delete_tree(root->right);
        free(root);
    }
    root=NULL;
    return;
}
int main()
{
    ll num,test,i,j,data,first,second;
    int query;
    struct node *root=NULL,*temp=NULL;
    cin>>num;
    while(num--)
    {
        cin>>i;
        root=insert_in_bst(root,i);
    }
    cin>>query;
    while(query--)
    {
        struct node *temp=NULL;
        cin>>first>>second;
        temp=find_lowest_common_ancestor(root,first,second);
        cout<<temp->data<<endl;
    }
    delete_tree(root);
}


