
vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    
    if(digits.size() == 0)
        return ans;
    
    map<char,string> m;
    
    m['2'] = "abc";m['3'] = "def";m['4'] = "ghi";
    m['5'] = "jkl";m['6'] = "mno";m['7'] = "pqrs";
    m['8'] = "tuv";m['9'] = "wxyz";
    
    ans.push_back("");
    
    for(int i = 0;i<digits.size();i++)
    {
        char x = digits[i];
        while(ans[0].size() == i)
        {
            string t = ans[0];
            ans.erase(ans.begin());
            string str = m[x];
            for(int j = 0;j<str.size();j++)
                ans.push_back(t+str[j]);
        }
    }
    
    return ans;
}
