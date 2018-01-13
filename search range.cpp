#include<iostream>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target)
{
    int s = 0, e = nums.size()-1,first=-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(target < nums[mid])
            e = mid-1;
        
        else if(target > nums[mid])
            s = mid+1;
         
         else
         {
            first = mid;  
            e = mid-1;
         }
    }
    
    int last = first;
    s = first + 1;
    e = nums.size()-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(target < nums[mid])
          e = mid-1;
        else if(target > nums[mid])
          s = mid+1;
         
        else
        {
            last = mid;
            s = mid+1;
        }
    }
    
    vector<int> ans(2,0);
    ans[0] = first;
    ans[1] = last;
    
    return ans;
    
    
}
