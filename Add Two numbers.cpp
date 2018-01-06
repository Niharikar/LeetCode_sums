#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* fun(ListNode* l1,ListNode* l2)
{
    ListNode* head = NULL;
    ListNode* temp ;
    int carry = 0;
    
    while(l1!=NULL || l2!=NULL)
    {
        if(head==NULL)
        {
            int sum = l1->val + l2->val;
            head = new ListNode(sum%10); 
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
            temp = head;
        }
        
        else
        {
            int sum = carry + l1->val + l2->val;
            ListNode* t = new ListNode(sum%10);
            carry = sum/10;
            temp->next = t;
            l1 = l1->next;
            l2 = l2->next;
            temp = t;
        }
        
    }    
    
    
    while(l1!=NULL)
    {
        int sum = carry + l1->val;
        ListNode* t = new ListNode(sum%10);
        carry = sum/10;
        temp->next = t;
        l1 = l1->next;
        temp = t;
    }
    
    while(l2!=NULL)
    {
        int sum = carry + l1->val;
        ListNode* t = new ListNode(sum%10);
        carry = sum/10;
        temp->next = t;
        l2 = l2->next;
        temp = t;
    }
    
    if(carry>0)
    {
        ListNode* t = new ListNode(carry);
        temp->next = t;
    }
    
    return head;
    
}
