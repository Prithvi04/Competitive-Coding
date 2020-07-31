// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next, *prev;
	
	Node (int x){
	    data = x;
	    next = NULL;
	    prev = NULL;
	}
};


 // } Driver Code Ends


/*
Structure of the node of the list is as
struct Node
{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
}; */


// Function to merge two DLLs
struct Node *mergesorted(struct Node* first,struct Node* second)
{
    if(!first)
    return second;
    
    if(!second)
    return first;
    
    if(first->data<second->data)
    {
        first->next=mergesorted(first->next,second);
        first->next->prev=first;
        first->prev=NULL;
        return first;
    }
    else
    {
        second->next=mergesorted(first,second->next);
        second->next->prev=second;
        second->prev=NULL;
        return second;
    }
}
struct Node *split(struct Node* head)
{
    Node *slow=head;
    Node *fast=head;
    while(fast->next && fast->next->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        
    }
    Node *temp=slow->next;
    slow->next=NULL;
    return temp;
}
struct Node *sortDoubly(struct Node *head)
{
	// Your code here
	if(!head ||head->next==NULL)
	return head;
	
	Node *second=split(head);
	
	head=sortDoubly(head);
	second=sortDoubly(second);
	
	return mergesorted(head,second);
	
	
}


// { Driver Code Starts.

void insert(struct Node **head, int data)
{
	struct Node *temp = new Node (data);
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

void print(struct Node *head)
{
	struct Node *temp = head;
	while (head)
	{
		cout<<head->data<<' ';
		temp = head;
		head = head->next;
	}
	cout<<endl;
	while (temp)
	{
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
}

// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}


// Driver program
int main(void)
{
    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = sortDoubly(head);
        print(head);
    }
	return 0;
}
  // } Driver Code Ends