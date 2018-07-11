

string alienOrder(vector<string>& words)
{
    map<char,set<char>> m;
    map<char,int> mc;
    
    for(int i = 0;i<words.size();i++)
    {
        for(int j = 0;j<words[i].size();j++)
          mc[words[i][j]] = 0;
    }
    
    for(int i = 0;i<words.size()-1;i++)
    {
        int j = 0;
        char c1 = words[i][j],c2 = words[i+1][j];
        int len = min(words[i].size(),words[i+1].size());
        
        while(words[i][j]==words[i+1][j] && j<len)
            j++;
        
        set<char> s;
        if(m.count(words[i][j]))
          s = m[words[i][j]];
        if(!s.count(words[i+1][j]))
        {
            s.insert(words[i+1][j]);
            m[words[i][j]] = s;
            mc[words[i+1][j]]++;
        }        
    }
    
    map<char,int>::iterator it = mc.begin();
    queue<char> q;
    while(it!=mc.end())
    {
        if(it->second == 0)
            q.push(it->first);
        it++;
    }
    
    string ans = "";
    while(!q.empty())
    {
      char c = q.front();q.pop();
      ans = ans + c;
      if(m.count(c))
      {
          for(char x: m[c])
          {
              mc[x]--;
              if(mc[x] == 0)
                  q.insert(x);
          }
      }
    }
    
    return ans.size()!=mc.size() ? "" : ans;
    
}
