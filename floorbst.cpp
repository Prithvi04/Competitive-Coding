// { Driver Code Starts
//Initial Template for C++
// CPP code to find floor of a key in BST 
#include <bits/stdc++.h> 
using namespace std; 

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node* insert(Node* root, int key) 
{ 
	if (!root) 
		return new Node(key); 
	if (key < root->data) 
		root->left = insert(root->left, key); 
	else
		root->right = insert(root->right, key); 
	return root; 
} 



 // } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};*/

/*This function is used to find floor of a key*/
int floor(Node* root, int key) 
{ 
	if (!root) 
		return INT_MAX; 

	// Your code here
	//Node *curr;
	
	    if(root->data==key)
	    return root->data;
	    else if(root->data>key)
	    {
	        //curr=root;
	        return floor(root->left,key);
	    }
	    
	    int floorvalue=floor(root->right,key);
	    return (floorvalue<=key)?floorvalue:root->data;
	   

}


// { Driver Code Starts.

int main() 
{ 
	
	int t;
	cin >> t;
	while(t--){
	    Node* root = NULL;
	    int n, x;
	    cin >> n;
	    int arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	        if(root == NULL) root = insert(root, arr[i]);
	        else insert(root, arr[i]);
	    }
	    cin >> x;
	    cout << floor(root, x) << endl; 
	}
	
	return 0; 
}  // } Driver Code Ends