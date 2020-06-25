
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;
	
	Node(char x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

struct Node* insert(struct Node* root,char data)
{
    if(root==NULL){
        root= new Node(data);
        return root;
    }

    else if(root->data<data)
    root->right=insert(root->right,data);

    else if(root->data>data)
    root->left=insert(root->left,data);

  return root;
}







struct Node* insertString(struct Node* root,string s, int *j)
{

    if((*j)>=s.length())
    return NULL;

	          if(s[*j]=='(')
	          (*j)++;


	         if(s[*j]!='('&&s[*j]!=')'){
	             
	             char n=0;
	             n = s[*j];
             (*j)++;

	          root=insert(root,n);

	          //cout<<"root->data="<<root->data<<endl;

	         // (*j)++;

	          if(s[*j]==')'){
                root->left=NULL;
              root->right=NULL;
              //cout<<"root->data="<<root->data<<endl;
              //cout<<"root->left=NULL\n";
              //cout<<"root->right=NULL\n";
              return root;
	          }

	         }

             if(s[*j]=='(')
	          (*j)++;

	          if(s[*j]==')'){
	            //  cout<<"root->data="<<root->data<<endl;
              //cout<<"root->left=NULL\n";
	          root->left=NULL;
	          }
              else{
                //    cout<<"root->left->parent->data="<<root->data<<endl;
	          root->left=insertString(root->left,s,j);
              }

//cout<<"right\n";

              while(s[*j]==')')
	          (*j)++;

	          if(s[*j]=='(')
	          (*j)++;

	          if(s[*j]==')'){
      //        cout<<"root->data="<<root->data<<endl;
        //      cout<<"root->right=NULL\n";
	          root->right=NULL;
	          (*j)++;
	          }
	          else{
          //    cout<<"root->right->parent->data"<<root->data<<endl;
              root->right=insertString(root->right,s,j);
	          }
return root;
}

void print(struct Node* root)
{

    if(root==NULL)
        return;


    print (root->left);
    cout<<root->data<<endl;
    print(root->right);

}
bool dupSub(Node *root);

int main() {
	//code
	int i,j,k,T ,level;
	char s[500];

	   cin>>T;

	   for(i=0;i<T;i++)
	   {
	     // cin>>level;

	      cin>>s;

	      int j=0;

	      struct Node* root=NULL;

	      root=insertString(root,s,&j);
	   
        cout<<dupSub(root)<<endl;

	  

	   }




	return 0;
}

// } Driver Code Ends


/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

/*This function returns true if the tree contains 
a duplicate subtree of size 2 or more else returns false*/
string dupsub(Node* root,unordered_set<string>&st)
{
	//The idea is to use serialization and hashing.
	//we use postorder to serialize here
    string s="";
    
    if(root==NULL)
    return s+'$'; //Marker for a NULL pointer
    
    string l=dupsub(root->left,st); // left subtree
    if(l.compare(s)==0) //left subtree dosen't have a duplicate
    return s;
    
    string r=dupsub(root->right,st); //right subtree
    if(r.compare(s)==0) //right subtree dosen't have a duplicate
    return s;
    
    s+=root->data+l+r;  //add root

    // If current subtree already exists in hash 
    // table. [Note that size of a serialized tree 
    // with single node is 3 as it has two marker 
    // nodes.
    
    if(s.size()>3 && st.find(s)!=st.end())
    return "";
    
    st.insert(s); //insert into the hashset for future lookups
    
    return s;
}
bool dupSub(Node *root)
{
     //your code here
     if(root==NULL)
     return false;
     
     unordered_set<string>st;
     string s=dupsub(root,st);
     
     if(s.compare("")==0)
     return true;
     
     return false;
}