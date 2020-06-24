// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int findDist(Node *, int, int);

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        cout << findDist(root, n1, n2) << "\n";
    }
    return 0;
}// } Driver Code Ends


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/* Should return minimum distance between a and b
   in a tree with given root*/
   int dist(Node* root,int t,int count)
   {
       if(root=NULL)
       return -1;
       
       if(root->data==t)
       {
           return count;
       }
       int lh=dist(root->left,t,count+1);
       
       
       return lh!=-1?lh:dist(root->right,t,count+1);
       
   }
Node* lca(Node* root,int a,int b)
{
    if(root==NULL)
    return NULL;
    
    if(root->data==a || root->data==b)
    return root;
    
    Node* lca1=lca(root->left,a,b);
    Node* lca2=lca(root->right,a,b);
    
    if(lca1!=NULL && lca2!=NULL)
    return root;
    
    if(lca1!=NULL)
    return lca1;
    else
    return lca2;
}

int findDist(Node* root, int a, int b) {
    // Your code here
    Node* LCA=lca(root,a,b);
    //if(LCA!=NULL)
    //{
        int ad=0;
        int x=dist(LCA,a,ad);
        int bd=0;
        int y=dist(LCA,b,bd);
        return x+y;
    //}
    //else
    //return 0;
    
    
    
}