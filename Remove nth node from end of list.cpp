#include<iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode* next;
  ListNode(int x): val(x),next(NULL){}
};

ListNode* Remove(ListNode* head,int n)
{
    ListNode* temp = head;
    
    while(temp!=NULL && n--)    // reaching n+1 position or end of list when n is equal to or greater than length of list
      temp = temp->next;
      
    if(temp==NULL && n == 0 )     // n==0  and temp==NUll, indicate when given value of n equals length of list, removing the head of list 
    {
        head = head->next;
        return head;
    }  
    
    if(temp==NULL && n > 0)       // in case when given n value is more than length of list, returning head as it is.
        return head;
    
    ListNode* t = head;ListNode* tp;         // second pointer and its previous pointer
    while(temp!=NULL)                         // till first pointer reaches NULL
    {
        tp = t;
        t=t->next;
        temp = temp->next;
    }
                    // updating the pointers for removing the desired node from the list.
    tp->next = t->next; 
    return head;
    
    
}
