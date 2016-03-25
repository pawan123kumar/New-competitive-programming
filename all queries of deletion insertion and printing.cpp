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
int main()
{
    ll num,test,i,j,data;
    int query;
    struct node *root=NULL;
    cin>>test;
    while(test--)
    {
        cin>>query;//query 1 is for insertion
        if(query==1)
        {
            cin>>data;
            root=insert_in_bst(root,data);
        }
        else if(query==2)//query 2 is for deletion
        {
            cin>>data;
            root=delete_from_bst(root,data);
        }
        else if(query==3)//query 3 is only for searching
        {
            cin>>data;
            if(search_in_bst(root,data))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }//query 4 is for sorted output
        else
        {
            inorder_traversal(root);
            cout<<endl;
        }
    }
}

