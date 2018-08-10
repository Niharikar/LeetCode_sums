
struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
};

void connect(TreeLinkNode* root)
{
    TreeLinkNode* cur = root,*prev = NULL,*head = NULL;
    
    while(cur!=NULL)
    {
        while(cur!=NULL)
        {
            if(cur->left!=NULL)
            {
                if(prev!=NULL)
                {
                    prev->next = cur->left;
                }
                
                else
                {
                    head = cur->left;
                }
                
                prev = cur->left;
            }
            
            if(cur->right!=NULL)
            {
                if(prev!=NULL)
                {
                    prev->next = cur->right;
                }
                
                else
                {
                    head = cur->right;
                }
                
                prev = cur->right;
            }
            
            cur = cur->next;
        }
        
        cur = head;
        head = prev = NULL;
        
    }
    
    
    
}
