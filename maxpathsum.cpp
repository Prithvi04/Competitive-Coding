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

int maxPathSum(Node *);

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        cout << maxPathSum(root) << "\n";
    }
    return 0;
}// } Driver Code Ends


/*Complete the function below
Node is as follows
struct Node{
    int data;
    Node *left, *right;
};
*/
int maxpath(Node* root,int &cal)
{
    if(root==NULL)
    return 0; //Base cases when root is NULL and when there's a single node 
    if(root->left==NULL && root->right==NULL)
    return root->data;
    
    //recursively calculates maxpath in left st and right st
    int ls=maxpath(root->left,cal);
    int rs=maxpath(root->right,cal);
    if(root->left!=NULL && root->right!=NULL)
    {
        //updates maxpathsum 
        cal=max(cal,ls+rs+root->data);
        
        //return the max of left st annd right st including the root
        return max(ls,rs)+root->data;
    }
    //when either of left st and right st is present
    
    return (root->left!=NULL ? root->data+ls : root->data+rs);
}
int maxPathSum(Node *root) {
    // code here
    int cal=INT_MIN;
    //Calculates maximum path sum from a leaf node to another leaf node.
    maxpath(root,cal);
    return cal;
}