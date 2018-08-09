

TreeNode* LCA(TreeNode* root,TreeNode* p,TreeNode* q)
{
    if(p->val > q->val)
        return LCA(root,q,p);
        
    if(root == NULL || root == p || root == q)
        return root;
        
     if(p->val < root->val && root->val < q)
        return root;
     
     if(root->val < p && root->val < q)
        return LCA(root->right,p,q);
     
     if(p < root->val && q < root->val)
        return LCA(root->left,p,q);
       
}
