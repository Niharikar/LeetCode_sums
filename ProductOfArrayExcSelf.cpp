

vector<int> productExceptSelf(vector<int>& nums)
{
    int left = nums[0];
    vector<int> ans(nums.size(),0);
    ans[0] = 1;ans[1] = nums[0];
    for(i = 2;i<nums.size();i++)
    {
        left *= nums[i-1];
        ans[i] = left;
    }
    
    int right = nums[nums.size()-1];
    ans[nums.size()-2] *= nums[nums.size()-1]; 
    
    for(int i = nums.size()-3;i>=0;i--)
    {
        right *= nums[i+1];
        ans[i] *= right;
    }
    
    return ans;
}
