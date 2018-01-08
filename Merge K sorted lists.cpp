#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* Merg2(ListNode* l1,ListNode* l2)
{
    ListNode* prehead = new ListNode(-1);
    ListNode* pre = prehead;
     while(l1!=NULL && l2!=NULL)
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
        
        pre->next = l1==NULL ? l2:l1
        
        return prehead->next;
}

ListNode* Merge(vector<ListNode*>& lists)
{
    
  while(lists.size()!=1)
  {
     
          ListNode* l1 = lists[k];
          ListNode* l2 = lists[k+1];
          lists[m++] = Merge2(l1,l2);     
  }  
   return lists[0]; 
    
}
