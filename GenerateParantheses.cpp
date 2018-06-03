

vector<string> generateParanatheses(int n)
{
    string s = "";
    vector<string> ans;
    DFS(ans,n,s,0,0)
    return ans;
}

void DFS(vector<string>& ans,int n,string s,int open,int close)
{
    if(s.size() == 2*n)
    {
        ans.push_back(s);
        return;
    }
    
    if(open<n)
     {
        s += "(";
        DFS(ans,n,s,open+1,close);
        s.erase(s.end()-1);
     }
     
     if(close<open)
     {
        s += ")";
        DFS(ans,n,s,open,close+1);
        s.erase(s.end()-1);
     }
    
}
