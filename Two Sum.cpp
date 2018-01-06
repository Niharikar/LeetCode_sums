#include<iostream>
#include<map>
using namespace std;
// brute force approach
vector<int> brute(vector<int>& nums,int target)
{
  vector<int> ans; 
  for(int i = 0; i < nums.size()-1;i++)
  {
      for(int j = i+1; j < nums.size();j++)
      {
          if(nums[i] + nums[j] == target)
          {
            ans.push_back(i);ans.push_back(j);
            return ans;
          } 
      }
  }
}


// best approach
vector<int> best(vector<int>& nums,int target)
{
    vector<int> ans(2,0);
    map<int,int> m;
    for(int i = 0 ;i<nums.size();i++)
    {
        int compl = target - nums[i];
        if(m.find(compl)!=m.end())
         {
            ans[0] = m[compl];
            ans[1] = i;
            return ans;
         }
        
        m[nums[i]] = i;
    }
}
