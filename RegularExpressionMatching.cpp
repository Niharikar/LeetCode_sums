

bool isMatch(string s, string p)
{
    vector< vector<int> > dp(s.size()+1,vector<int>(p.size()+1));
    
    dp[0][0] = 1;
    for(int j = 1;j<dp[0].size();j++)
    {
        if(p[j-1] == '*')
        {
            dp[i][j] = dp[i][j-2];
        }
    }
    
    for(int i = 1;i<dp.size();i++)
    {
        for(int j = 1;j<dp[0].size();j++)
        {
            if(p[j-1] == '.' || s[i-1] == p[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            
            else if(p[j-1] == '*')
            {
                dp[i][j] = dp[i][j-2];
                
                if(dp[i][j] == 0)
                {
                    if(s[i-1] == p[j-2] || p[j-2] == '.')
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    
    return dp[s.size()][p.size()];
}
