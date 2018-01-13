#include<iostream>
using namespace std;

int searchInsert(vector<int>& nums,int target)
{
    int s = 0,e = nums.size()-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(target <= nums[mid])
            e = mid-1;
        else
            s = mid+1;
    }
    
    return s;
    
}


//   This problem is similar to Binary search problem but only thing is we need to observe that "s" variable in th code in binary problem 
// will be the insert position, only thing to change is, we mix equal to condition with less than mid condition
