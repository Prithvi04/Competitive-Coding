// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
// A binary Tree node
struct node
{
    int data;
    struct node *left, *right;
};
int counter=0;
int target=0;
struct node *ptr=NULL;

int countkdistanceNode(node* root, node* target , int k);


 // } Driver Code Ends





//User function Template for C++

/*
struct node
{
    int data;
    struct node *left, *right;
}; */

/* Recursive function to print all the nodes at distance k in the
   tree (or subtree) rooted with given root. See  */
unordered_map<int,vector<int>>mp;
unordered_map<int,bool>visited;
void DFS(node *root)
{
    if(!root)
    return;
    if(root->left)
    {
        mp[root->data].push_back(root->left->data);
        mp[root->left->data].push_back(root->data);
    }
    if(root->right)
    {
        mp[root->data].push_back(root->right->data);
        mp[root->right->data].push_back(root->data);
        
    }
    DFS(root->left);
    DFS(root->right);
}
void countdisutil(int target,int k,int &count)
{
    if(visited.find(target)!=visited.end())
    return;
    
    visited[target]=true;
    if(k==0)
    {
        count++;
        visited[target]=true;
        return;
    }
    for(auto it:mp[target])
    countdisutil(it,k-1,count);
}
int countkdistanceNode(node *root, node* target,int k)
{
// Your code here
DFS(root);
int count=0;
countdisutil(target->data,k,count);
return count;
}



// { Driver Code Starts.

// A utility function to create a new binary tree node
node *newnode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 void insert(struct node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->data==n1)
     {
         switch(lr)
         {
          case 'L': root->left=newnode(n2);
                    break;
          case 'R': root->right=newnode(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
 
 
 void Inorder(struct node* root)
{

    if(counter==0)
    {
        cin>>target;
        counter++;
    }

    if(root==NULL)
        return ;

    Inorder(root->left);

    if(root->data==target)
         ptr=root;

    Inorder(root->right);
}
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct node *root=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=newnode(n1);
            switch(lr){
                    case 'L': root->left=newnode(n2);
                    break;
                    case 'R': root->right=newnode(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
    Inorder(root);
    node * target =ptr;
    cin>>k;
    cout << countkdistanceNode(root, target, k);
    cout<<endl;
    counter=0;
    }
    return 0;
}
  // } Driver Code Ends