

 struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };
  
void connect(TreeLinkNode* root)
{
    queue<TreeLinkNode*> q;
    q.push(root);
    
    while(!q.empty())
    {
        int size = q.size();
        
        for(int i = 0;i<size;i++)
        {
            TreeLinkNode* node = q.front();q.pop();
            
            if(i!= size-1)
              node->next = q.front();
              
            if(node->left!=NULL)
            {
              q.push(node->left);
              q.push(node->right);
            }
        }
    }
    
    
}
