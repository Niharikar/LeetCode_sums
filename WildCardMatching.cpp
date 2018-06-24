
bool isMatch(string s,string p)
{
    vector< vector<int> > dp(s.size()+1,vector<int>(p.size()+1,0));
    
    dp[0][0] = 1;
    for(int j = 1;j<p.size()+1;j++)
    {
        if(dp[0][j] == '*')
          dp[0][j] = dp[0][j-1];
    }
    
    for(int i = 1; i<s.size()+1;i++)
    {
        for(int j = 1;j<p.size()+1;j++)
        {
            if(s[i-1] == p[j-1] || p[j-1] == '?')
                dp[i][j] = dp[i-1][j-1];
                
             else if(p[j-1] == '*')
             {
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
             }
              
        }
    }
    
    return dp[s.size()][p.size()];
}
