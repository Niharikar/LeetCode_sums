
vector<int> maxSlidingWindow(vector<int>& nums,int k)
{
    if(nums.size()==0)
    {
        return nums;
    }
    
    vector<int> ans(nums.size()-k+1,0);
    int j = 0;
    deque<int> q;
    for(int i = 0;i<nums.size();i++)
    {
        if(!q.empty() && q.front() < i-k+1)
          q.pop_front();
        
        while(!q.empty() && nums[q.back()] < nums[i])
          q.pop_back();
          
        q.push_back(i);
        
        if(i>=k-1)
          ans[j++] = nums[q.font()]; 
            
    }
    
    return nums;
}
