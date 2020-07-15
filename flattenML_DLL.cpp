/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp=head;
        stack<Node* >s;
        while(head!=NULL)
        {
            if(head->child!=NULL)
            {
                if(head->next!=NULL)
                    s.push(head->next);//storing reference of next node of node containing the child for reconeccting back the next level
                head->next=head->child;//prev level to next level
                head->next->prev=head;
                head->child=NULL;
            }
            else if(head->next==NULL && !s.empty())
            {
                head->next=s.top();//conncecting with prev levels
                head->next->prev=head;
                s.pop();
            }
            head=head->next;//head will traverse all levels.
        }
        return temp;//return actual head.
        
    }
};