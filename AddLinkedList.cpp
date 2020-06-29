// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

struct Node* addTwoLists(struct Node* first, struct Node* second);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
struct ListNode
{
    unordered_map<Node*,Node*> _prev;
    struct Node* _tail;
  ListNode(struct Node* head)
  {
      struct Node* prev=NULL;
      while(head!=NULL)
      {
          _tail=head;
          _prev[head]=prev;
          prev=head;
          head=head->next;
      }
      
  }
  struct Node* getPrev(struct Node* curr)
  {
      return _prev[curr];
      
  }
  struct Node* getTail()
  {
      return _tail;
      
  }
  
};

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    // code here
    ListNode A(first),B(second);
    
    struct Node* f=A.getTail();
    struct Node* s=B.getTail();
    struct Node* res=NULL;
    int carry=0;
    while(f!=NULL && s!=NULL)
    {
        int curSum=f->data+s->data+carry;
        struct Node* ptr= new Node(curSum%10);
        carry=curSum/10;
        if(res==NULL)
        {
            res=ptr;
        }
        else
        {
            ptr->next=res;
            res=ptr;
            
        }
        f=A.getPrev(f);
        s=B.getPrev(s);
        
        
    }
    
    while(f!=NULL)
    {
        int curSum=f->data+carry;
        struct Node* ptr= new Node(curSum%10);
        ptr->next=res;
        res=ptr;
        carry=curSum/10;
        f=A.getPrev(f);
    }
    while(s!=NULL)
    {
        int curSum=s->data+carry;
        struct Node* ptr= new Node(curSum%10);
        ptr->next=res;
        res=ptr;
        carry=curSum/10;
        s=B.getPrev(s);
    }
    if(carry)
    {
        struct Node* ptr= new Node(curSum%10);
        ptr->next=res;
        res=ptr;
        
        
    }
    
    
    return res;
    
    
}
