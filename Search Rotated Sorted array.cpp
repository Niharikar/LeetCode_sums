#include<iostream>
using namespace std;

int Pivot(vector<int>& nums,int s,int e)
{ 
    while(1)
    {
         int m = (s+e)/2;
        if(nums[m] > nums[m+1)
          return m+1;

        if(nums[s] > nums[m])
            e = m-1;
        else
            s = m+1;
     }
}

int Binary(vector<int>& nums,int s,int e,int val)
{
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(val > nums[mid])
          s = mid+1;
        else if(val < nums[mid])
          e = mid-1;
         else
          return mid;
    }
    
    return -1;
}

int Search(vector<int>& nums,int target)
{
    if(nums.size()==0)
      return -1;
    if(nums.size()==1)
      return Binary(nums,0,0,target);
    
    if(nums[0] > nums[nums.size()-1])
    {
      int p = Pivot(nums,0,nums.size()-1);
      
      if(target <= nums[nums.size()-1])
        return Binary(nums,p,nums.size()-1,target);
      else
         return Binary(nums,0,p-1,target); 
    } 
    
    else
    {
        return Binary(nums,0,nums.size()-1,target);
    }
}
