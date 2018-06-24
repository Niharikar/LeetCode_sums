
vector< vector<int> > permute(vector<int>& nums)
{
    vector<int> temp;
    vector< vector<int> > ans;
    DFS(ans,temp,nums.size(),nums);
    
    return ans;
}

void DFS(vector<vector<int>>& ans,vector<int> temp,int n,vector<int>& nums)
{
    if(temp.size() == n)
    {
        ans.push_back(temp);
        return;
    }
    
    for(int i = 0;i<n;i++)
    {
        if(find(temp.begin(),temp.end(),nums[i]) != temp.end())
            continue;
        
        temp.push_back(nums[i]);
        DFS(ans,temp,n,nums);
        temp.erase(temp.begin()+ temp.size()-1);
    }
    
}
