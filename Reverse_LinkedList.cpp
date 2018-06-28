
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x). next(NULL) {}
};


//  iterative solution
ListNode* reverseList(ListNode* head)
{
    ListNode* rev = NULL;
     while(head)
     {
        ListNode* temp = head;
        head = head->next;
        temp->next = rev;
        rev = temp;
     }
     
     return rev;
}


// recursive solution

ListNode* reverseList(ListNode* head)
{
    return reverseList(head,NULL);  
}

ListNode* reverseList(ListNode* head,ListNode* prehead)
{
    if(head == NULL)
        return prehead;
    
    ListNode* next = head->next;
    head->next = prehead;
   return reverseList(next,head);
}

//

ListNode* reverseList(ListNode* head,ListNode* rev)
{
    if(head == NULL)
        return rev;
        
     ListNode* t = head;
     head = head->next;
     t->next = rev;
     return reverseList(head,t);
}
