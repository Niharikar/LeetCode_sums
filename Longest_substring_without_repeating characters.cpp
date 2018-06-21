

// sliding window optimized

int lengthOfLongestSubstring(string s)
{
    map<char,int> m;
    int j = 0,ans;
    for(int i = 0;i<s.size();i++)
    {
        if(m.find(s[i])!=m.end())
          j = max(m[s[i]],j);
         
         ans = max(ans,i-j+1);
         m[s[i]] = i+1;
    }
    
    return ans;
}


// sliding window

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> st;
    int j = 0,ans,i = 0;
    
    while(i<s.size() && j<s.size())
    {
        if(!st.count(s[j]))
        {
          st.insert(s[j++]);
          ans = max(ans,j-i);
        }
        
        else
        {
            st.erase(s[i++]);
        }
    }
    
    return ans;
}
