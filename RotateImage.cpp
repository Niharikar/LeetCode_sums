

void rotate(vector< vector<int>>& m)
{
    int n = m.size();
    
    for(int k = 0;k<=n/2;k++)
    {
        for(int i = n-1,j = n-1 ;i!=j; i--,j--)
        {
            swap(m[i][k],m[k][j]);
        }
      
     }
     
     for(int i = 0;i<n;i++) 
      reverse(m[i].begin(),m[i].end());
     
     
}
