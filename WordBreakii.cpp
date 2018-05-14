
vector<string> wordBreak(string s,vector<string>& wordDict)
{
    map<string,vector<string>> m;
    return DFS(s,wordDict,m);
}

vector<string> DFS(string s,vector<string>& wordDict,map<string,vector<string>>& m)
{
    if(m.find(s)!=m.end())
      return m[s];
     
    vector<string> res;
    if(s.size()==0)
    {
        res.push_back("");
        return res;
    }
    
    for(string word : wordDict)
    {   
        if(!strncmp(s.c_str,word.c_str,word.size()))
        {
            vector<string> sublist = DFS(s.substr(word.size()),wordDict,m);
            for(string sub:sublist)
            {
                res.push_back(word + (sub.size()==0 ? "" : " ") + sub);           
            }
        }
    }
    
    m[s] = res;
    return res;
}
