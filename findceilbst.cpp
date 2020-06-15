int findCeil(Node* root, int input) 
{ 
    // Base case 
    if (root == NULL) 
        return -1;
    
   
  
    // Your code here
    if (root == NULL) 
        return -1; 
  
    // We found equal key 
    if (root->data == input) 
        return root->data; 
  
    // If root's key is smaller, ceil must be in right subtree 
    if (root->data < input) 
        return findCeil(root->right, input); 
  
    // Else, either left subtree or root has the ceil value 
    int ceil = findCeil(root->left, input); 
    return (ceil >= input) ? ceil : root->data;
}