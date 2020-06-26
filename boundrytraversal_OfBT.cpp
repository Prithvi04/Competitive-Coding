// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> printBoundary(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector <int> res = printBoundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */
void printleftview(Node *root,vector<int>&res)
{
    if(root==NULL)
    return;
    
    if(root->left)
    {
        res.push_back(root->data);
        printleftview(root->left,res);
    }
    else if(root->right)
    {
        res.push_back(root->data);
        printleftview(root->right,res);
    }
    
}
void printleaves(Node *root,vector<int>&res)
{
    if(root==NULL)
    return;
    
    printleaves(root->left,res);
    if(root->left==NULL && root->right==NULL)
    {
        res.push_back(root->data);
    }
    
    printleaves(root->right,res);
    
    
}
void printrightview(Node *root,vector<int>&res)
{
    if(root==NULL)
    return;
    
    if(root->right)
    {
        printrightview(root->right,res);
        res.push_back(root->data);
    }
    else if(root->left)
    {
        printrightview(root->left,res);
        res.push_back(root->data);
    }
    
}
vector <int> printBoundary(Node *root)
{
     //Your code here
     vector<int>res;
     if(root!=NULL)
     res.push_back(root->data);
     //divide the problem into three functions
     printleftview(root->left,res);//left view
     printleaves(root,res);//print all the leaves
     printrightview(root->right,res);//right view.
     
     return res;
}