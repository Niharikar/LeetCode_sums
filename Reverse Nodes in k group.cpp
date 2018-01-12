#include<iostream>
using namespace std;

ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL){}
};

ListNode* reverseK(ListNode* head,int k)
{
    ListNode* prehead = new ListNode(-1);
    int num = 0;
    prehead->next head;
    
    ListNode* temp = prehead;
    
    while(temp->next!=NULL)
      num++;
      
    ListNode *cur,*nex,*pre = prehead; 
    while(num>=k)
    {
      cur = pre->next;
      nex = cur->next;
        for(int i = 1;i<k;i++)
        {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        num = num-k;
    }
    
    return prehead->next;
}
