

struct Node
{
  Node* left;
  Node* right;
  int val;
  Node(int x): val(x), left(NULL), right(NULL) {}
};


int maxPathSum(Node* root)
{
  int maxsum = INT_MIN;
  maxi(root,maxsum);
  return maxsum;
}

int maxi(Node* node, int& m)
{
    if(node==NULL)
      return 0;
      
    int left = max(0,maxi(node->left,m));
    int right = max(0,maxi(node->right,m));
    m = max(m,left+right +node->val);
    return max(left,right) + node->val; 
}
