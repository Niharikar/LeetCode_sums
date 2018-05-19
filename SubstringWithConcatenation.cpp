
vector<int> findSubstring(string s,vector<string>& words)
{
    if(words.size() == 0 && s.size() == 0)
      return {};

    int dictlen = words.size();
    int wordlen = words[0].size();
    int n = s.size();
    vector<int> ans;
    unordered_map<string,int> dict;
    for(string word:words)
    {
        dict[word]++;
    }
    
    for(int i = 0;i<wordlen;i++)
    {
        int start = i;
        int len = 0;
        unordered_map<string,int> temp;
        
        while(start+(dictlen-len)*wordlen - 1 < n)
        {
            string cur = s.substr(start + len*wordlen,wordlen);
            
            if(dict[cur] == 0)
            {
                start = start + (len+1)*wordlen;
                len = 0;
                temp = unordered_map<string,int>();
            }
            
            else
            {
                len++;
                temp[cur]++;
                while(temp[cur] > dict[cur])
                {
                    string pre = s.substr(start,wordlen);
                    temp[pre]--;
                    len--;
                    start = start + wordlen;
                }
                
                if(len == dictlen)
                {
                    ans.push_back(start);
                }
            }
        }
    }
    
    return ans;
    
}
