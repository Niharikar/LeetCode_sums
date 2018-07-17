

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        return dfs(root,0,root->val-1);
    }
    
    int dfs(TreeNode* node,int l,int prev)
    {
      if(node == NULL)
          return l;

        if(node->val != prev+1)
        {
            return max(l,dfs(node,0,node->val-1));
        }

        return max(dfs(node->left,l+1,node->val), dfs(node->right,l+1,node->val));
    }
            
    
};
