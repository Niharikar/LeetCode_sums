#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

// recursive approach constant space
ListNode* Merge(ListNode* l1,ListNode* l2)
{
    if(l1==NULL && l2==NULL)
      return NULL;
      
    if(l1==NULL)
      return l2;
    if(l2==NULL)
      return l1;
     
     
     if(l1->val > l2->val)
     {
        l2->next = Merge(l1,l2->next);
        return l2;
     }
     else
     {
        l1->next = Merge(l1->next,l2);
        return l1;
     }
     
}

ListNode* Merging(ListNode* l1,LisNode* l2)
{
    ListNode* prehead = ListNode(-1);
    
    ListNode* pre = prehead;
    
    while(l1!NULL && l2!=NULL)
    {
        if(l1->val <= l2->val)
        {
            pre->next = l1;
            l1 = l1->next;
        }
        
        else
        {
            pre->next = l2;
            l2 = l2->next;
        }
        
        pre = pre->next;
    }
    
    pre->next = (l1==NULL) ? l2:l1;
    
    return prehead.next;
    
}
