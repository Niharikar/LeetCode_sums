
vector<int> spiralOrder(vector< vector<int>>& a)
{
    int u = 0,d = a.size()-1,l = 0,r = a[0].size()-1;
    vector<int> ans = 0;
    while(1)
    {
        for(int i = l;i<=r;i++)
          ans.push_back(a[u][i]);
        if(++u > d)
          break;
        
        for(int i = u;i<=d;i++)
            ans.push_back(a[i][r]);
        if(--r < l)
           break;
         
         for(int i = r;i>=l;i--)
            ans.push_back(a[d][i]);
         if(--d < u)
            break;
            
         for(int i = d;i>=u;i--)
            ans.push_back(a[i][l]);
         if(++l > r)
            break;
    }
    
    return ans;
}
