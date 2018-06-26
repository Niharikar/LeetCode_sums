
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


// another method with O(n) space complexity

vector<int> maxSlidingWindow(vector<int>& nums,int k)
{
    vector<int> leftmax(nums.size(),0);
    vector<int> rightmax(nums.size(),0);
    
    leftmax[0] = nums[0];
    for(int i = 1;i<nums.size();i++)
    {        
        if(i%(k) == 0)
            leftmax[i] = nums[i];
        else
            leftmax[i] = max(nums[i],leftmax[i-1]);

    }

    
    rightmax[nums.size()-1] = nums[nums.size()-1];
    for(int i = nums.size()-2;i>=0;i--)
    {
        if(i%k == 0)
            rightmax[i] = nums[i];
        else
            rightmax[i] = max(nums[i],rightmax[i+1]);
    
    }    
    
    vector<int> ans;
    for(int i = 0;i<(nums.size()-(k-1));i++)
        ans[i] = max(rightmax[i],leftmax[i+k-1]);
    
    return ans;
    
}
