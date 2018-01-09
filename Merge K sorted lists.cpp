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

// time complexity is O(Nk) O(1) space complexity, k is length of Lists, N is length of each linked list 
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

// time complexity is O(NLogK), space compexity is O(1)
ListNode* Merge(vector<ListNode*>& lists)
{
    int interval = 1;
    
    while(interval < lists.size())
    {
        for(int i = 0;i<lists.size();i += 2*interval)
        {
            lists[i] = Merge2(lists[i],lists[i+interval]);
        }
        
        interval = 2*interval;
    }
    
    return lists[0];
}

    

