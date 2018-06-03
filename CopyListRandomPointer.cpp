struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };


RandomListNode* copyRandomList(RandomlistNode* head)
{
    RandomListNode* chead = new RandomListNode(head->label);
    RandomListNode* temp = head;
    RandomListNode* ct = chead;
    while(temp->next)
    {
        temp = temp->next;
        RandomListNode* t = new RandomListNode(temp->label);
        ct->next = t;
        ct = t;
    }
    ct->next = NULL;
    
    map<RandomListNode*,RandomListNode*> mp;
    temp = head;ct = chead;
    while(temp)
    {
        mp[temp] = ct;
        temp = temp->next;
        ct = ct->next;
    }
    
    ct = chead;temp = head;
    while(ct)
    {
        ct->random = m[temp->random];
        ct = ct->next;
        temp = temp->next;
    }
    
    return chead;
    
    
}
