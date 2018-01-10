#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL){}
};

ListNode* SwapPairs(ListNode* head)
{
    if(head==NULL || head->next==NULL)
      return head;
      
    ListNode* cur = head;
    head = cur->next;
    ListNode* temp;
    while(cur!=NULL && cur->next!=NULL)
    {
        temp = cur;
        cur = cur->next;
        temp->next = cur->next;
        cur->next = temp;
        cur = temp->next;
        if(cur!=NULL && cur->next!=NULL) 
            temp->next = cur->next;        
    }
    
    return head;
}
