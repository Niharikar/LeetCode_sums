
string longestCommonPreix(vector<string>& strs)
{
    int minLen = 0;
    
    for(auto s:strs)
      minLen = min(minLen,s.size());
    
    int s = 0,e = minLen;
    
    while(s<=e)
    {
        int mid = s +(e-s)/2;
        
        if(isCommonPrefix(strs,mid))
          s = mid+1;
        else
          e = mid-1;
    }
    
    return strs[0].substr(0,(s+e)/2);
}

bool isCommonPrefix(vector<string>& strs, int m)
{
    string str = strs[0];
    
    for(int i = 1;i<strs.size();i++)
    {
        if(strs[i].substr(0,m) != str)
            return false;
    }
    
    return true;
}
